
using System.Collections.Generic;
using System;
using System.Text;


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

