
using System;
using System.Text;

public class Solution
{
    public int[] SearchRange(int[] nums, int target)
    {
        int l = 0, r = nums.Length - 1;
        int lpos = -1;
        int[] x = { -1, -1 };
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int midv = nums[mid];
            if (midv < target)
            {
                l = mid + 1;
            }
            else if (midv > target)
            {
                r = mid - 1;
            }
            else
            {
                r = mid;
            }
        }
        if (l == r && nums[l] == target)
        {
            x[0] = l;
        }
        else
        {

            return x;
        }


        l = lpos;
        r = nums.Length - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int midv = nums[mid];
            if (midv < target)
            {
                l = mid + 1;
            }
            else if (midv > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        x[1] = l;
        return x;
    }
    public static int Main()
    {
        Solution s = new Solution();
        var p = s.SearchRange([], 2);
        Console.WriteLine(p[0] + "," + p[1]);
        return 0;
    }
}
