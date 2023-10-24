class Solution {
public:

    int helper(int i , int j , vector<vector<int>>& tri , int n , vector<vector<int>>& dp){

        // if already cal
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        // if we are at bottom row  , return the value of the curr cell
        if(i == n-1)
        return tri[i][j] ;


        int down = tri[i][j] + helper(i+1 , j , tri , n , dp) ;
        int dg = tri[i][j] + helper(i+1 , j+1 , tri , n , dp) ;


        //store the min if the both
        return dp[i][j] = min(down , dg) ;
    }


    int minimumTotal(vector<vector<int>>& tri){
        int n = tri.size() ;
        vector<vector<int>> dp(n , vector<int>(n  , -1));
        return helper(0 , 0 , tri , n , dp) ;
    }
};