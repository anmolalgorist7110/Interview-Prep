class Solution {
public:

    int helper(int n , vector<int>& arr , vector<int>& dp){
        dp[0] = arr[0] ;

        for(int i=1 ; i<n ; i++){
            int p = arr[i] ;
            if(i>1){
                p += dp[i-2] ;
            }

            int np = dp[i-1] ;

            dp[i] = max(p,np) ;
        }

        return dp[n-1] ;

    }

    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n , 0) ;

        return helper(n , nums , dp) ;
    }
};