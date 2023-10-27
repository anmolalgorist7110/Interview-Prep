class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size() ;

        bool table[n][n] ;
        memset(table , 0 , sizeof(table)) ;

        // all substr of len 1
        // are palindrome

        int maxlen = 1 ;

        for(int i=0 ; i<n; i++){
            table[i][i] = true ;
        }


        int start = 0 ;
        for(int i=0 ; i<n-1 ; i++){
         if(str[i] == str[i+1]){
             table[i][i+1] = true ;
             start = i ;
             maxlen = 2 ;
         }
        }

        for(int k=3 ; k<=n ; k++){
            // fill the index
            for(int i=0 ; i<n-k+1 ; i++){
                // get the index of the substring from 
                // starting index i and length k
                int j = i+k-1 ;

                // checking for substring from ith index to 
                // jth index if str[i+1] to str[j-1] is a palindrome

                if(table[i+1][j-1] and str[i] == str[j]){
                    table[i][j] = true ;

                    if(k>maxlen){
                        start = i ;
                        maxlen = k ;
                    }
                }
            }
        }

        string ans = "" ;
        for(int j = start ; j<= start + maxlen - 1 ; j++){
            ans += str[j] ;
        }

        return ans ;
    }
};