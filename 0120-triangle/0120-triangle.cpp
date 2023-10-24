class Solution {
public:

    int helper(vector<vector<int>>& tri , int n){
        vector<vector<int>> dp(n , vector<int>(n , 0)) ;


        //init the bottom row of the dp with the values from tri
        for( int j=0 ; j<n ; j++){
            dp[n-1][j] = tri[n-1][j] ;
        }


        //iterate through the tri rows in reverse order

        for(int i = n-2 ; i>=0 ; i--){
            for(int j=i ; j>=0 ; j--){
          
            // calculate the min path sum for the current cell
            int down = tri[i][j] + dp[i+1][j] ;
            int dg = tri[i][j] + dp[i+1][j+1] ;

            //store the min of the two possible path in dp
            dp[i][j] = min(down ,dg) ;

            }
        }

        return dp[0][0] ;
    }

    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size() ;
        return helper(tri  , n) ;
    }
};