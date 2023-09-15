//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int s(int ind , int* arr , vector<int>& dp){
	    
	    if(dp[ind] != -1){
	        return dp[ind] ;
	    }
	    
	    //base case
	    if(ind == 0){
	        return arr[ind] ;
	    }
	    if(ind <0) return 0 ;
	    
	    
	    int p = arr[ind] + s(ind - 2 , arr , dp) ;
	    int np = 0 + s(ind -1 , arr , dp) ;
	    
	    
	    //store the result in the dp table and retur it
	       return dp[ind] = max(p , np) ;
	}
	
	int findMaxSum(int *arr, int n) {
	
	    vector<int> dp(n, -1) ;
	    return s(n-1 , arr , dp) ;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends