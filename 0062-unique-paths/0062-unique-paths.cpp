class Solution {
public:

   int helper(int m , int n , vector<vector<int>>& dp){
      // loop throug the grid using twonested loops

      for(int i=0 ; i<m ; i++){
          for(int j = 0 ; j<n ;j++){
              // base case 
              if(i==0 and j==0){
                  dp[i][j] = 1 ;
                  continue ;
              }


              int up = 0 ;
              int left = 0 ;

              if(i>0)
              up = dp[i-1][j] ;

              if(j>0)
              left = dp[i][j-1] ;

              dp[i][j] = up + left ;
          }
      }

      return dp[m-1][n-1] ;
   }


    int uniquePaths(int m, int n) {
       // create a memo table (dp) to store the results of subproblems
       vector<vector<int>> dp(m , vector<int>(n , -1)) ;

       // call the utilty function with the bottom-right cell
       return helper(m , n , dp) ;
    }
};