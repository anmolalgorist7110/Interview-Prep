function sortByBits(arr: number[]): number[] {
const D = new Map();

        for (let i of arr) {
            const count = i.toString(2).split('1').length - 1;
            if (!D.has(count)) {
                D.set(count, []);
            }
            D.get(count).push(i);
        }

        const result = [];
        for (let k of [...D.keys()].sort((a, b) => a - b)) {
            D.get(k).sort((a, b) => a - b);
            result.push(...D.get(k));
        }

        return result;
};