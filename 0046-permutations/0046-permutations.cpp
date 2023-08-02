//TIME:O(!n*n)
//SPACE:O(n)+O(n)

class Solution {
	private:
		void helper(vector<int>&ds , vector<int> &nums ,vector<vector<int>> &ans , int freq[]){
			if(ds.size() == nums.size()){
				ans.push_back(ds) ;
				return ;
			}
			
			for(int i=0 ; i<nums.size() ;i++){
				// if it is unmarked
				if(!freq[i]){
					ds.push_back(nums[i]) ;
					freq[i] = 1 ;
					helper(ds , nums , ans , freq) ;
					freq[i] = 0 ;
					ds.pop_back() ;
				}
			}
		}
	
public:
    vector<vector<int>> permute(vector<int>& nums) {
    	// number of permuation will n!
        vector<vector<int>>ans ; // goona store all  the final permuation
        vector<int> ds ; // store that particular permuation on a particluar recursive call
        int freq[nums.size()] ; // gonna take note whether that particular index element taken or not
        for(int i=0 ;i<nums.size() ; i++){
        	freq[i] =0 ;
		}
        helper(ds , nums , ans , freq) ;
        return ans ;
    }
};