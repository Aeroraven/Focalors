
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{
    public void RecursiveCombine(int cur, int target, int last, int n, IList<IList<int>> container, int[] stack)
    {
        if (cur == target)
        {
            IList<int> newAnswer = new List<int>();
            for (int i = 0; i < target; i++)
            {
                newAnswer.Add(stack[i]);
            }
            container.Add(newAnswer);
            return;
        }
        for (int i = last + 1; i <= n; i++)
        {
            stack[cur] = i;
            int placeRemain = target - cur - 1;
            int numRemain = n - last;
            if (numRemain < placeRemain)
            {
                return;
            }
            RecursiveCombine(cur + 1, target, i, n, container, stack);
        }
    }
    public IList<IList<int>> Combine(int n, int k)
    {
        int[] stack = new int[k];
        IList<IList<int>> answer = new List<IList<int>>();
        RecursiveCombine(0, k, 0, n, answer, stack);
        return answer;
    }
    public static int Main()
    {
        Solution s = new Solution();
        var p = s.Combine(20, 10);
        foreach (var x in p)
        {
            foreach (var w in x)
            {
                Console.Write(w + ",");
            }
            Console.WriteLine();
        }
        return 0;
    }
}
