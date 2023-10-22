function maximumScore(nums: number[], k: number): number {
let res = nums[k];
        let i = k;
        let j = k;
        let min_val = nums[k];

        while (i > 0 || j < nums.length - 1) {
            if (i === 0) {
                j += 1;
                min_val = Math.min(min_val, nums[j]);
            } else if (j === nums.length - 1) {
                i -= 1;
                min_val = Math.min(min_val, nums[i]);
            } else if (nums[i - 1] > nums[j + 1]) {
                i -= 1;
                min_val = Math.min(min_val, nums[i]);
            } else {
                j += 1;
                min_val = Math.min(min_val, nums[j]);
            }

            res = Math.max(res, min_val * (j - i + 1));
        }

        return res;
};