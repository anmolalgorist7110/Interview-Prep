//TIME: O(log m*n) 
//SPACE: O(1) 




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        if(matrix.empty())
        return false ;
        
        
        const int m  = matrix.size() ;
        const int n = matrix[0].size() ;
        
        
        
        int l = 0 ;
        int r = m*n ;
        
        
        while(l<r)
        {
        	const int mid = l + (r-l)/2 ;// with the help of the mid we will found corresponding element "i" and "j" index 
        	// in the matrix
        	const int i = mid/n ; // this is the row index in the matrix 
        	const int j = mid%n ;// this is the col index in the matrix
        	
        
        		
        	if(matrix[i][j] == target)
        	return true ;
        	
        	// implementing the imaginary bianry searh in the matrix
        	if(matrix[i][j] < target)
        	l = mid+1 ;
        	else
        	r = mid ;
		}
		
		return false ;
        
        
    }
};