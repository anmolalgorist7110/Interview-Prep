/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    // total length
    let N = cost.length;

    // used only for memoization
    let dp = {} ;
    const getMinCost = (index) => {
        // if index is  0 or neg..
        //index 0 means we have just crossed index 1 with min cost
        if(index <= 1){
            return 0 ;
        }

        //memoization logic
        if(dp[index]){
            return dp[index] ;
        }

        //get the cost of left
        // as we are moving down we go to index-1 and we will take cost of that index
        let left = getMinCost(index-1) + cost[index-1] ;

        // as we  are moving down we go to the index-2 and we will take cost of that index
        let right = getMinCost(index-2) + cost[index-2] ;

        dp[index] = Math.min(left , right);
        return Math.min(left , right) ;
    };

    return getMinCost(N) ;
};