class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        int provinces = 0 ;
        vector<bool> visited(n , false) ;


        for(int i=0 ; i<n ;i++){
            if(!visited[i]){
                provinces++ ;
                dfs(isConnected , visited , i) ;
            }
        }

        return provinces ;
    }

    void dfs(vector<vector<int>>& isConnected , vector<bool>& visited , int node){
        visited[node] = true ;
        for(int nei = 0 ; nei < isConnected.size() ; nei++){
            if(isConnected[node][nei] == 1 and !visited[nei]){
                dfs(isConnected , visited , nei);
            }
        }
    }
};