using System;

public class Solution
{
    public long MaxArrayValue(int[] nums)
    {
        int n = nums.Length;
        long cur = 0;
        long ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            cur = (nums[i] > cur) ? nums[i] : cur + nums[i];
            ans = Math.Max(ans, cur);
        }
        return ans;
    }
    static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.MaxArrayValue([5, 3, 3]));
        return 0;
    }
}