function findKOr(nums: number[], k: number): number {
    let ret = 0;
    for (let j = 0; j <= 30; j++) {
        let counter = 0;
        for (let i = 0; i < nums.length; i++) {
            if ((nums[i] & (1 << j)) == (1 << j)) {
                counter++;
            }
            if (counter >= k) {
                ret |= (1 << j);
                break;
            }
        }
    }
    return ret;
};
