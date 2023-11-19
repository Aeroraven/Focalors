

using System.Collections.Generic;
using System;
using System.Text;

public class Solution
{
    public IList<IList<int>> FourSum(int[] nums, int target)
    {
        Array.Sort(nums);
        List<IList<int>> answer = new List<IList<int>>();
        if (nums.Length < 3)
        {
            return answer;
        }
        for (int i = 3; i < nums.Length; i++)
        {
            if (i < nums.Length - 1 && nums[i] == nums[i + 1])
            {
                continue;
            }
            for (int j = i - 1; j >= 2; j--)
            {
                if (j < i - 1 && nums[j] == nums[j + 1])
                {
                    continue;
                }
                // Find (c,d) that satisfies:
                // I. A[a]+A[b]+A[c]+A[d] = target
                // II. c<d<a<b

                int c = 0, d = j - 1;
                while (c < d)
                {
                    while (c > 0 && nums[c - 1] == nums[c] && c < d)
                    {
                        c++;
                    }
                    while (d < j - 1 && nums[d] == nums[d + 1] && d > c)
                    {
                        d--;
                    }
                    if (c == d) break;
                    if (((long)nums[i] + (long)nums[j] + (long)nums[c] + (long)nums[d]) == target)
                    {
                        int[] p = { nums[c], nums[d], nums[j], nums[i] };
                        answer.Add(p);
                        Console.WriteLine("Answer Added:" + nums[c] + "," + nums[d] + "," + nums[j] + "," + nums[i]);
                    }
                    if (nums[i] + nums[j] + nums[c] + nums[d] > target)
                    {
                        d--;
                    }
                    else
                    {
                        c++;
                    }
                }
            }
        }
        return answer;
    }

    public static int Main()
    {
        Solution s = new Solution();
        s.FourSum([1000000000, 1000000000, 1000000000, -1000000000], -5);
        return 0;
    }
}
