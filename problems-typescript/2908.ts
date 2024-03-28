function minimumSum(nums: number[]): number {
    let ans = 200000
    for(let i=0;i<nums.length;i++){
        let left = 20000,right=20000;
        for(let j=0;j<i;j++){
            if(nums[j]<nums[i])left=Math.min(nums[j],left);
        }
        for(let j=i+1;j<nums.length;j++){
            if(nums[j]<nums[i])right=Math.min(nums[j],right);
        }
        ans = Math.min(ans,left+right+nums[i])
    }
    if(ans>=10000) ans = -1;
    return ans
};