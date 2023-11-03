function buildArray(target: number[], n: number): string[] {
    const result: string[] = [];
    let stream = 1;
    for (const val of target) {
        result.push('Push');
        while (val !== stream++) result.push('Pop', 'Push');
    }
    return result;
};