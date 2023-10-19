//TIME:O(N)
//SPACE:O(N)


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t) ;
    }
    
    private:
    	string helper(string& s){
    		string stack ;
    		for(char c : s){
    			if(c!='#'){
    				stack.push_back(c) ;
				}else if(!stack.empty()){
					stack.pop_back() ;
				}
			}
			
			return stack ;
		}
};