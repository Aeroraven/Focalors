
using System;

public class Solution
{
    public int MaxMoves(int[][] grid)
    {
        int r = grid.Length, c = grid[0].Length;
        int[,] f = new int[2, r];
        int ans = 0;
        for (int i = 1; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                f[i % 2, j] = -2000;
                int lb = Math.Max(j - 1, 0);
                int rb = Math.Min(j + 1, r - 1);
                for (int k = lb; k <= rb; k++)
                {
                    if (grid[j][i] > grid[k][i - 1])
                    {
                        f[i % 2, j] = Math.Max(f[i % 2, j], f[(i + 1) % 2, k] + 1);
                        ans = Math.Max(f[i % 2, j], ans);
                    }
                }
            }
        }
        return ans;
    }
    public static int Main()
    {
        Solution s = new Solution();
        int[][] grid = [[2, 4, 3, 5], [5, 4, 9, 3], [3, 4, 2, 11], [10, 9, 13, 15]];
        Console.WriteLine(s.MaxMoves(grid));
        return 0;
    }
}