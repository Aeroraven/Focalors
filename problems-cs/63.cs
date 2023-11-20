
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public int UniquePathsWithObstacles(int[][] obstacleGrid)
    {
        int r = obstacleGrid.Length;
        int c = obstacleGrid[0].Length;
        int[,] f = new int[r, c];

        f[0, 0] = (1 - obstacleGrid[0][0]);


        for (int i = 1; i < c; i++)
        {
            f[0, i] = f[0, i - 1] * (1 - obstacleGrid[0][i]);
        }
        for (int i = 1; i < r; i++)
        {
            f[i, 0] = f[i - 1, 0] * (1 - obstacleGrid[i][0]);
        }
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                f[i, j] = (f[i - 1, j] + f[i, j - 1]) * (1 - obstacleGrid[i][j]);
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
