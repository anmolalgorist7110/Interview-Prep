function constrainedSubsetSum(nums: number[], k: number): number {
    const n = nums.length, queue: number[] = [ 0 ];
    let result = nums[ 0 ], zero = 0;
    for ( let i = 1; i < n; i++ ) {
        const max = nums[ queue[ zero ] ];
        if ( max > 0 ) nums[ i ] += max;
        while ( queue.length > zero && nums[ queue[ queue.length - 1 ] ] <= nums[ i ] ) queue.pop();
        queue.push( i );
        if ( i - queue[ zero ] >= k ) zero++;
        if ( result < nums[ i ] ) result = nums[ i ];
    }
    return result;
};