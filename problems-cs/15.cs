using System.Collections.Generic;
using System;

public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        List<IList<int>> answer = new List<IList<int>>();

        Array.Sort(nums);
        HashSet<int> visited = new HashSet<int>();
        HashSet<int> usedAlternative = new HashSet<int>();

        for (int i = 0; i < nums.Length; i++)
        {
            // Check if to preserve hash table
            if (i == 0 || nums[i] != nums[i - 1])
            {
                usedAlternative.Clear();
            }

            // Add solutions
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (usedAlternative.Contains(nums[j]))
                {
                    continue;
                }
                if (visited.Contains(-nums[i] - nums[j]))
                {
                    int[] x = { -nums[i] - nums[j], nums[i], nums[j] };
                    answer.Add(x);
                    usedAlternative.Add(nums[j]);
                }
            }
            visited.Add(nums[i]);
        }
        return answer;
    }
    public static int Main()
    {
        Solution s = new Solution();
        int[] a = { 0, 0, 0, 1, 1 };
        IList<IList<int>> r = s.ThreeSum(a);
        foreach (var item in r)
        {
            Console.WriteLine("" + item[0] + "," + item[1] + "," + item[2]);
        }
        return 0;
    }
}
