using System.Collections.Generic;
using System;

public class Solution
{
    private static int[][] d = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    public void Search(char[][] grid, int x, int y)
    {
        grid[x][y] = '0';
        Queue<int> qx = new Queue<int>();
        Queue<int> qy = new Queue<int>();
        qx.Enqueue(x);
        qy.Enqueue(y);
        while (qx.Count > 0)
        {
            var px = qx.Dequeue();
            var py = qy.Dequeue();
            for (int i = 0; i < 4; i++)
            {
                int cx = px + d[i][0];
                int cy = py + d[i][1];
                if (cx >= 0 && cx < grid.Length && cy >= 0 && cy < grid[0].Length)
                {
                    if (grid[cx][cy] == '1')
                    {
                        grid[cx][cy] = '0';
                        qx.Enqueue(cx);
                        qy.Enqueue(cy);
                    }
                }
            }
        }
    }
    public int NumIslands(char[][] grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.Length; i++)
        {
            for (int j = 0; j < grid[0].Length; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    Search(grid, i, j);
                }
            }
        }
        return ans;
    }

    public static int Main()
    {
        char[][] p = [
            ['1', '1', '0', '0', '0'],
            ['1', '1', '0', '0', '0'],
            ['0', '0', '1', '0', '0'],
            ['0', '0', '0', '1', '1']
        ];
        Solution s = new Solution();
        Console.WriteLine(s.NumIslands(p));
        return 0;
    }
}