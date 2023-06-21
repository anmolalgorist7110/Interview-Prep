class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
          int n = nums.size();
       vector<pair<int,int>>arr;
       long long sum = 0;
       for(int i=0;i<n;i++){
           arr.push_back({nums[i],cost[i]});
           sum += cost[i];
       }
       sort(arr.begin(),arr.end());
       long long N = (sum+1)/2;
       int x = -1;
       for(int i=0;i<n;i++){
           N -= arr[i].second;
           if(N<=0){
            x = arr[i].first;
            break;
           }
       }
     long long ans = 0;
     for(int i=0;i<n;i++){
      ans += (long long)abs( (long long) x*cost[i]-(long long) nums[i]*cost[i]);   
     }
     return ans;
    }
};