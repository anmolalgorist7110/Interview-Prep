class Solution {

    /**
     * @param Integer[][] $graph
     * @return Integer
     */
    function shortestPathLength($graph) {
    $n = count($graph);
    $allVisited = (1 << $n) - 1;
    $queue = new SplQueue();
    $visited = [];

    for ($i = 0; $i < $n; $i++) {
        $queue->enqueue([1 << $i, $i, 0]);
        $visited[(1 << $i) * 16 + $i] = true;
    }

    while (!$queue->isEmpty()) {
        [$mask, $node, $dist] = $queue->dequeue();

        if ($mask === $allVisited) {
            return $dist;
        }

        foreach ($graph[$node] as $neighbor) {
            $newMask = $mask | (1 << $neighbor);
            $hashValue = $newMask * 16 + $neighbor;

            if (!isset($visited[$hashValue])) {
                $visited[$hashValue] = true;
                $queue->enqueue([$newMask, $neighbor, $dist + 1]);
            }
        }
    }

    return -1;
}
}