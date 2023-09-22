class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0 ; // for index of str1 
        // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1

    for(int i=0 ; i<t.length() and j<s.length() ; i++)
    if(s[j] == t[i])
    j++ ;

    // if all chars of str1 were found in str2 
    return (  j == s.length()) ;
    }
};