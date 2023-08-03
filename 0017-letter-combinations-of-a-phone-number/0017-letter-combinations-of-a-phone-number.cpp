class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /// if digit size is zero
        if(digits.size() == 0){
            return {} ;
        }
        
        // storing all the posibble combinations
        vector<string> ans ;
        
        const vector<string> poss = {"0" , "1" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"} ;
        
        string current = "" ;
        helper(current , 0 ,digits , poss , ans) ;
        return ans ;
    }
    
    void helper(string current , int i ,const string& digits , const vector<string>&poss ,vector<string>& ans){
        if(i == digits.size()){
               ans.push_back(current) ;
               return ;
        }
        
        int d = digits[i] - '0' ;
        for(char ch : poss[d]){
         helper(current+ch , i+1 ,digits , poss ,ans) ;
        }
    }
};