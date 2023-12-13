using System.Collections.Generic;
using System;

public class Solution
{
    public int MinimumTotal(IList<IList<int>> triangle)
    {
        int[,] f = new int[2, triangle.Count];
        f[0, 0] = triangle[0][0];
        for (int i = 1; i < triangle.Count; i++)
        {
            f[i % 2, 0] = f[(i - 1) % 2, 0] + triangle[i][0];
            f[i % 2, i] = f[(i - 1) % 2, i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++)
            {
                f[i % 2, j] = Math.Min(f[(i - 1) % 2, j], f[(i - 1) % 2, j - 1]) + triangle[i][j];
            }

        }
        int answer = 0x7fffffff;
        for (int i = 0; i < triangle.Count; i++)
        {
            answer = Math.Min(answer, f[(triangle.Count - 1) % 2, i]);
        }
        return answer;
    }
    public static int Main()
    {
        int[][] x = [[-10]];
        Solution sol = new Solution();
        Console.WriteLine(sol.MinimumTotal(x));
        return 0;
    }
}