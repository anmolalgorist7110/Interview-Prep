class Solution {
public:

    bool helper(vector<int>& nums , int mid ,  int p){
        int check = 0 ;
        int cnt  = 0 ;
        int n = nums.size() ;
        for(int i=1 ; i<n ; i++){
            if(check){
                check = 0 ;
                continue ;
            }

            if(nums[i] - nums[i-1] <= mid){
                check = 1 ;
                cnt++ ;
            }
        }

        return cnt >= p ;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        int low = 0 , high = nums[n-1] - nums[0] ;
        int ans = INT_MAX ; 
        while(low <= high){
           int mid = low + (high-low)/2 ;
           if(helper(nums , mid , p)){
               ans = mid ;
               high = mid-1 ;
           }else{
               low = mid +1 ;
           }
        }

        return ans ;
    }
};