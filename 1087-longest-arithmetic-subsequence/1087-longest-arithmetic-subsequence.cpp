class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size() ;
        vector<unordered_map<int,int>> dp(n) ;
        int ln = 2 ;


        for(int j=0 ; j<n ; j++){
            for(int i=0 ; i<j ; i++){
                int diff = nums[j] - nums[i] ;

                dp[j][diff] = dp[i].count(diff) ? dp[i][diff]+1 :2 ;
                ln = max(ln , dp[j][diff]) ;
            }
        } 
        return ln ;
    }
};