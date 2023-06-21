/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
   var n = nums.length , val = 0 ;

   if(n==0){
       return init ;
   }

    if(n==1){
        val = fn(init , nums[0]) ;
        return  val ;
    }

    if(n>1){
        val = fn(init , nums[0]) ;
        for(var i=1 ; i<n ; i++){
            val = fn(val , nums[i]) ;
        }
    }

    return val ;

};