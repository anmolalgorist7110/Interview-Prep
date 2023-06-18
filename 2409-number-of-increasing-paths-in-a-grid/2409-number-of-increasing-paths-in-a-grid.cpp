//TIME: O(M*N)

class Solution {
public:

   int helper(vector<vector<int>>& grid , int i , int j , vector<vector<int>>& dp , int prev){
       if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or prev >= grid[i][j])
       return 0 ;

       if(dp[i][j] !=  -1)
       return dp[i][j] ;

       int top = helper(grid , i-1 , j , dp , grid[i][j]) ;
       int bottom = helper(grid , i+1 , j , dp , grid[i][j]) ;
       int right = helper(grid , i , j+1 , dp , grid[i][j]) ;
       int left = helper(grid, i , j-1 ,dp , grid[i][j]) ;


       dp[i][j] = (1 + top + bottom + right + left)%1000000007;
       return dp[i][j] ;
   }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size()  ;

        if(m==1 and n==1)
        return 1 ;

        vector<vector<int>> dp(m , vector<int>(n, -1)) ;

        int ans = 0; 

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(dp[i][j] == -1)
                ans = (ans + helper(grid , i , j , dp , -1))%1000000007 ;
                else
                ans = (ans + dp[i][j])%1000000007 ;
            }
        }

        return ans ;
    }
};