using System;

public class Solution
{
    public int FindMaxForm(string[] strs, int m, int n)
    {
        int ns = strs.Length;
        int[,] cost = new int[ns, 2];
        int[,,] f = new int[2, m + 1, n + 1];
        for (int i = 0; i < ns; i++)
        {
            for (int j = 0; j < strs[i].Length; j++)
            {
                if (strs[i][j] == '0') cost[i, 0]++;
                else cost[i, 1]++;
            }
        }
        for (int i = 0; i < ns; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    f[i % 2, j, k] = f[(i + 1) % 2, j, k];
                }
            }
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (j + cost[i, 0] <= m && k + cost[i, 1] <= n)
                    {
                        f[i % 2, j + cost[i, 0], k + cost[i, 1]] = Math.Max(f[i % 2, j + cost[i, 0], k + cost[i, 1]], f[(i + 1) % 2, j, k] + 1);
                    }
                }
            }
        }
        int ret = 0;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                ret = Math.Max(f[(ns - 1) % 2, j, k], ret);
            }
        }
        return ret;
    }
}