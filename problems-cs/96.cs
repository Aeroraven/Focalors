
using System.Collections.Generic;
using System;
using System.Text;
public class Solution
{
    public bool CanFinish(int numCourses, int[][] prerequisites)
    {
        List<int>[] outs = new List<int>[numCourses];
        int[] prereqs = new int[numCourses];
        for (int i = 0; i < numCourses; i++)
        {
            outs[i] = new List<int>();
        }
        foreach (var p in prerequisites)
        {
            outs[p[1]].Add(p[0]);
            prereqs[p[0]]++;
        }
        Queue<int> q = new Queue<int>();
        for (int i = 0; i < numCourses; i++)
        {
            if (prereqs[i] == 0)
            {
                q.Enqueue(i);
            }
        }
        int cn = 0;
        while (q.Count > 0)
        {
            cn++;
            var t = q.Dequeue();
            foreach (var v in outs[t])
            {
                prereqs[v]--;
                if (prereqs[v] == 0)
                {
                    q.Enqueue(v);
                }
            }
        }
        return cn == numCourses;
    }
    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.CanFinish(2, [[1, 0]]));
        return 0;
    }

}

public class Solution
{
    public int NumTrees(int n)
    {
        int[] f = new int[n + 1];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                f[i] += f[j - 1] * f[i - j];
            }
        }
        return f[n];

    }
    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.fun(2));

        return 0;
    }
}

