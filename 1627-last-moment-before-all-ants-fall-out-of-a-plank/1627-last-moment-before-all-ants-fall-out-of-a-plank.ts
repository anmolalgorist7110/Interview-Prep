const getLastMoment = (plankLength: number, left: number[], right: number[]): number => {
    let i;
    const leftLength = left.length;
    const rightLength = right.length;
    let longestDuration = 0;
    for(i=0; i <= plankLength; i++) {
        if(i > leftLength && i > rightLength) {
            break;
        }
        if(i < leftLength && left[i] > longestDuration) {
            longestDuration = left[i];
        }
        if(i < rightLength && plankLength - right[i] > longestDuration) {
            longestDuration = plankLength - right[i];
        }
        // console.log(`i: ${i}, longest:${longestDuration}`)
    }
    return longestDuration;
};