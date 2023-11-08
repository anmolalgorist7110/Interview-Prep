const isReachableAtTime = (sx: number, sy: number, fx: number, fy: number, t: number): boolean => 
    sx === fx && sy === fy
    ? t !== 1
    : Math.abs(sx - fx) <= t && Math.abs(sy - fy) <= t