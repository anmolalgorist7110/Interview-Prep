function findArray(pref: number[]): number[] {
    const n = pref.length;
    const arr = new Array(n);

    arr[0] = pref[0];

    for (let i = 1; i < n; i++) {
        arr[i] = pref[i] ^ pref[i - 1];
    }

    return arr;
}