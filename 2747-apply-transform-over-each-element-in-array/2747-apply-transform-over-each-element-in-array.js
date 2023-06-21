/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const newarr = new Array(arr.length);
    for(let i=0 ; i<arr.length ; i++){
        newarr[i] = fn(arr[i] , i)
    }
    return newarr ;
};