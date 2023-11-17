using System;

public class Solution
{
    public int MaxArea(int[] height)
    {
        int l = 0;
        int r = height.Length - 1;
        int maxAns = 0;
        while (l < r)
        {
            maxAns = Math.Max(maxAns, (r - l) * Math.Min(height[l], height[r]));
            if (height[l] <= height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxAns;

    }
    public static int Main()
    {
        Solution s = new Solution();
        return 0;
    }
}
