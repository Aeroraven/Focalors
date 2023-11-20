
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public int MinPathSum(int[][] grid)
    {
        int r = grid.Length;
        int c = grid[0].Length;
        int[,] f = new int[r, c];

        f[0, 0] = grid[0][0];


        for (int i = 1; i < c; i++)
        {
            f[0, i] = f[0, i - 1] + grid[0][i];
        }
        for (int i = 1; i < r; i++)
        {
            f[i, 0] = f[i - 1, 0] + grid[i][0];
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                f[i, j] = Math.Min(f[i - 1, j], f[i, j - 1]) + grid[i][j];
            }
        }
        return f[r - 1, c - 1];
    }
    public static int Main()
    {
        Solution s = new Solution();

        return 0;
    }
}