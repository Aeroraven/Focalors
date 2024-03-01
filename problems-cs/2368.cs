using System.Collections.Generic;
using System;

public class Solution
{
    public int ReachableNodes(int n, int[][] edges, int[] restricted)
    {
        List<int>[] edgeList = new List<int>[n];
        bool[] vis = new bool[n];
        bool[] ban = new bool[n];
        for (int i = 0; i < n; i++)
        {
            edgeList[i] = new List<int>();
        }
        for (int i = 0; i < edges.Length; i++)
        {
            edgeList[edges[i][0]].Add(edges[i][1]);
            edgeList[edges[i][1]].Add(edges[i][0]);
        }
        for (int i = 0; i < restricted.Length; i++)
        {
            ban[restricted[i]] = true;
        }

        int ans = 0;
        vis[0] = true;
        Queue<int> q = new Queue<int>();
        q.Enqueue(0);
        while (q.Count > 0)
        {
            int front = q.Dequeue();
            ans++;
            for (int i = 0; i < edgeList[front].Count; i++)
            {
                if (!vis[edgeList[front][i]] && !ban[edgeList[front][i]])
                {
                    vis[edgeList[front][i]] = true;
                    q.Enqueue(edgeList[front][i]);
                }
            }
        }
        return ans;
    }
    public static int Main()
    {

        int[][] a = [[0, 1], [1, 2], [3, 1], [4, 0], [0, 5], [5, 6]];
        int[] r = [4, 5];
        Solution s = new Solution();
        Console.WriteLine(s.ReachableNodes(7, a, r));
        return 0;
    }
}