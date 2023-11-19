
using System.Collections.Generic;
using System;
using System.Text;

public class IntervalComparer : IComparer<int[]>
{
    public int Compare(int[]? x, int[]? y)
    {
        if (x[0] < y[0])
        {
            return -1;
        }
        return 1;
    }
}
public class Solution
{
    public int[][] Merge(int[][] intervals)
    {
        IntervalComparer comparer = new IntervalComparer();
        Array.Sort(intervals, comparer);
        int r = -1, l = -1;

        List<int[]> ints = new List<int[]>();
        for (int i = 0; i < intervals.Length; i++)
        {
            if (intervals[i][0] > r)
            {
                if (r > -1)
                {
                    int[] w = { l, r };
                    ints.Add(w);
                }
                l = intervals[i][0];
            }
            r = Math.Max(r, intervals[i][1]);
        }
        int[] s = { l, r };
        ints.Add(s);
        return ints.ToArray();
    }
    public static int Main()
    {
        Solution s = new Solution();
        var x = s.Merge([[1, 3], [2, 6], [8, 10], [15, 18]]);
        foreach (var i in x)
        {
            Console.WriteLine(i[0] + "," + i[1]);
        }

        return 0;
    }
}
