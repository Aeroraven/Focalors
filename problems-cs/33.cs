
using System;
using System.Text;

public class Solution
{
    public int Search(int[] nums, int target)
    {
        // First find the rotation position
        int l = 0, r = nums.Length - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            int midval = nums[mid];
            if (midval < nums[0])
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        int pv = l + 1;
        int rotl = pv;
        // Then find target using binary search
        l = 0;
        r = nums.Length - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int midval = nums[(mid + rotl) % nums.Length];
            if (midval > target)
            {
                r = mid - 1;
            }
            else if (midval < target)
            {
                l = mid + 1;
            }
            else
            {
                return (mid + rotl) % nums.Length;
            }
        }
        return -1;
    }
    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.Search([4, 5, 6, 7, 0, 1, 2], 1));
        return 0;
    }
}
