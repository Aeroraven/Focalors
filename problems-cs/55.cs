
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{
    public bool CanJump(int[] nums)
    {
        int rightPos = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (i > rightPos)
            {
                return false;
            }
            rightPos = Math.Max(rightPos, nums[i] + i);
        }
        return true;
    }
    public static int Main()
    {
        Solution s = new Solution();

        Console.WriteLine(s.CanJump([3, 2, 1, 0, 4]));
        return 0;
    }
}
