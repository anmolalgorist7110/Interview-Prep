function poorPigs(b: number, latency: number, testDur: number): number {
    // Total states one pig can be in
    let rounds: number = testDur / latency + 1, n = 0
    // Find min n where rounds^n >= b
    while (rounds ** n < b) n++
    return n
}