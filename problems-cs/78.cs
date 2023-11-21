using System.Collections.Generic;
using System;

public class Solution
{
    public void FindSubsets(int idx, int[] a, IList<IList<int>> container, int[] tmp, int len)
    {
        IList<int> newAnswer = new List<int>();
        for (int i = 0; i < len; i++)
        {
            newAnswer.Add(tmp[i]);
        }
        container.Add(newAnswer);
        for (int i = idx; i < a.Length; i++)
        {
            if (i > idx && a[i] == a[i - 1]) continue;
            tmp[len] = a[i];
            FindSubsets(i + 1, a, container, tmp, len + 1);
        }
    }
    public IList<IList<int>> Subsets(int[] nums)
    {
        Array.Sort(nums);
        IList<IList<int>> answer = new List<IList<int>>();
        int[] temp = new int[nums.Length];
        FindSubsets(0, nums, answer, temp, 0);
        return answer;
    }
}