class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& v,int k,int n,int start){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=n;i++){
            v.push_back(i);
            helper(ans,v,k,n,i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,v,k,n,1);
        return ans;
    }
};