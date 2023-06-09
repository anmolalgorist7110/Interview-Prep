/*-----------------------------------USING 2D DP----------------------------------------------------------------------------*/
//TIME: O(n)
//SPACE: O(n)


class Solution {
public:
    int climbStairs(int n) {
        // DP[i] = no of distinct ways to climb to ith stairs
        vector<int> dp(n+1) ;
        dp[0] = 1 ;
        dp[1] = 1  ;
        
        
        
        for(int i=2 ; i<=n ;i++)
        {
        	dp[i] = dp[i-1] + dp[i-2] ;
		}
		
		
		return dp[n] ;
    }
};