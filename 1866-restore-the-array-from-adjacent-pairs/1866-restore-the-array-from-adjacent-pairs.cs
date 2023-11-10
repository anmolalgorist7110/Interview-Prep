public class Solution {
    public int[] RestoreArray(int[][] adjacentPairs) {
        Dictionary<int, List<int>> adjacencyMap = new Dictionary<int, List<int>>();

        // Build the adjacency map
        foreach (var pair in adjacentPairs) {
            if (!adjacencyMap.ContainsKey(pair[0])) {
                adjacencyMap[pair[0]] = new List<int>();
            }
            if (!adjacencyMap.ContainsKey(pair[1])) {
                adjacencyMap[pair[1]] = new List<int>();
            }

            adjacencyMap[pair[0]].Add(pair[1]);
            adjacencyMap[pair[1]].Add(pair[0]);
        }

        // Find the start node (a node with only one adjacent node)
        int startNode = adjacencyMap.Keys.First(key => adjacencyMap[key].Count == 1);

        // Perform DFS to reconstruct the array
        List<int> result = new List<int>();
        HashSet<int> visited = new HashSet<int>();
        DFS(startNode, adjacencyMap, visited, result);

        return result.ToArray();
    }

    private void DFS(int node, Dictionary<int, List<int>> adjacencyMap, HashSet<int> visited, List<int> result) {
        visited.Add(node);
        result.Add(node);

        foreach (var neighbor in adjacencyMap[node]) {
            if (!visited.Contains(neighbor)) {
                DFS(neighbor, adjacencyMap, visited, result);
            }
        }
    }
}