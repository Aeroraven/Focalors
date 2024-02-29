using System;

public class Solution
{
    public int FindTargetSumWays(int[] nums, int target)
    {
        int s = 0;
        foreach (var x in nums) s += x;
        if (target > s || target < -s) return 0;
        int[,] f = new int[21, (2 * s + 3)];
        f[0, s] = 1;
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = 0; j <= 2 * (s + 1); j++)
            {
                if (j + nums[i] <= 2 * s + 1)
                {
                    f[i + 1, j] += f[i, j + nums[i]];
                }
                if (j - nums[i] >= 0)
                {

                    f[i + 1, j] += f[i, j - nums[i]];
                }

            }
        }
        return f[nums.Length, target + s];
    }
    public static int Main()
    {
        Solution solution = new Solution();
        int[] nums = { 1, 1, 1, 1, 1 };
        Console.WriteLine(solution.FindTargetSumWays(nums, 3));
        return 0;
    }
}
