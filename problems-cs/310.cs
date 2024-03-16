using System.Collections.Generic;
using System;

public class Solution
{
    List<int>[] e;
    int[] visited;
    int[] down;
    int[] f;
    int n;
    int minv = 0xfffffff;
    int dfs1(int u)
    {
        visited[u] = 1;
        down[u] = 1;
        foreach (var v in e[u])
        {
            if (visited[v] == 1) continue;
            down[u] = Math.Max(down[u], 1 + dfs1(v));
        }
        return down[u];
    }

    void dfs2(int u, int top)
    {
        visited[u] = 2;
        f[u] = Math.Max(down[u] - 1, top);
        minv = Math.Min(f[u], minv);
        int deepestChild = -1;
        int secondChild = -1;
        foreach (var v in e[u])
        {
            if (visited[v] == 2) continue;
            if (deepestChild == -1)
            {
                deepestChild = v;
            }
            else
            {
                if (down[deepestChild] < down[v])
                {
                    deepestChild = v;
                }
            }
        }
        foreach (var v in e[u])
        {
            if (visited[v] == 2) continue;
            if (v == deepestChild) continue;
            if (secondChild == -1)
            {
                secondChild = v;
            }
            else
            {
                if (down[secondChild] < down[v])
                {
                    secondChild = v;
                }
            }
        }
        foreach (var v in e[u])
        {
            if (visited[v] == 2) continue;
            if (v == deepestChild)
            {
                int xf = ((secondChild == -1) ? 0 : (1 + down[secondChild]));
                xf = Math.Max(xf, top + 1);
                dfs2(v, xf);
            }
            else
            {
                int xf = down[deepestChild] + 1;
                xf = Math.Max(xf, top + 1);
                dfs2(v, xf);
            }
        }
    }
    public IList<int> FindMinHeightTrees(int n, int[][] edges)
    {
        this.n = n;
        this.e = new List<int>[n];
        this.visited = new int[n];
        this.down = new int[n];
        this.f = new int[n];
        List<int> ans = new List<int>();
        for (int i = 0; i < n; i++)
        {
            e[i] = new List<int>();
        }
        foreach (var x in edges)
        {
            e[x[0]].Add(x[1]);
            e[x[1]].Add(x[0]);
        }
        int a = dfs1(0);
        dfs2(0, 0);

        for (int i = 0; i < n; i++)
        {
            if (f[i] == minv)
            {
                ans.Add(i);
            }
        }
        return ans;
    }

    public static int Main()
    {
        Solution s = new Solution();
        var p = s.FindMinHeightTrees(6, [[1, 0], [1, 2], [1, 3]]);
        foreach (var x in p)
        {
            Console.WriteLine(x);
        }

        return 0;
    }
}