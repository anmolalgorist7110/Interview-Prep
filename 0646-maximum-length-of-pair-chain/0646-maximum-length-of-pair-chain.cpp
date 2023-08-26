class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       int n = pairs.size() ;
        if(!n)
       return 0 ;
   
        
        sort(pairs.begin() , pairs.end()) ;
   
   // LIS initalized as 1 As , every elemnt is itself an aswer
   vector<int>lis(n , 1) ;
   int longestchain  = 1 ;
   
   for(int i=1 ; i<n ;i++){
       for(int j=0 ; j<i ; j++){
           // consition silimialr to LIS
           if(pairs[j][1] < pairs[i][0] and (lis[i] < lis[j] +1)){
               lis[i] = lis[j] + 1 ;
               
               //updating max
               longestchain = max(longestchain , lis[i]) ;
           }
       }
   }
       
       return longestchain ;
    }
};