using System.Collections.Generic;
using System;

public class Solution
{
    public void RecPermute(int[] a, int ord, int[] p, bool[] mark, IList<IList<int>> container)
    {
        if (ord == a.Length)
        {
            List<int> ints = new List<int>();
            for (int i = 0; i < a.Length; i++)
            {
                ints.Add(p[i]);
            }
            container.Add(ints);
            return;
        }
        for (int i = 0; i < a.Length; i++)
        {
            if (i > 0 && a[i] == a[i - 1]) continue;
            if (mark[i]) continue;
            p[ord] = a[i];
            mark[i] = true;
            RecPermute(a, ord + 1, p, mark, container);
            mark[i] = false;
        }
    }
    public IList<IList<int>> Permute(int[] a)
    {
        //46
        Array.Sort(a);
        List<IList<int>> answer = new List<IList<int>>();
        bool[] marks = new bool[a.Length];
        int[] perm = new int[a.Length];
        for (int i = 0; i < a.Length; i++)
        {
            marks[i] = false;
        }
        RecPermute(a, 0, perm, marks, answer);
        return answer;

    }
}