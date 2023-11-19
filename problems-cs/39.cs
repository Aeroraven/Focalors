
using System.Collections.Generic;
using System;
using System.Text;

public class Solution
{
    public int dTargets = 0;
    public int dCands = 0;
    public int stTop = 0;
    public int[]? aCands = null;
    public void RecursiveGetCombinations(int curPos, int curCap, bool[,] dv, IList<IList<int>> solution, IList<int> curPlace)
    {
        if (curPos == -1)
        {
            // Add answer here
            List<int> list = new List<int>();
            for (int i = 0; i < aCands.Length; i++)
            {
                for (int j = 0; j < curPlace[i]; j++)
                {
                    list.Add(aCands[i]);
                }
            }
            solution.Add(list);
            return;
        }
        if (curPos == 0)
        {
            if ((curCap - 0) % this.aCands[curPos] == 0)
            {
                curPlace[curPos] = (curCap - 0) / this.aCands[curPos];
                RecursiveGetCombinations(curPos - 1, 0, dv, solution, curPlace);
            }
            return;
        }

        for (int i = 0; i <= curCap; i++)
        {
            if (dv[curPos - 1, i] == true && (curCap - i) % this.aCands[curPos] == 0)
            {
                curPlace[curPos] = (curCap - i) / this.aCands[curPos];
                RecursiveGetCombinations(curPos - 1, i, dv, solution, curPlace);
            }
        }
    }
    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        aCands = candidates;
        dTargets = target;
        dCands = candidates.Length;
        bool[,] f = new bool[candidates.Length, target + 1];
        IList<IList<int>> answer = new List<IList<int>>();
        IList<int> cpv = new List<int>();
        //Init
        for (int i = 0; i < candidates.Length; i++)
        {
            cpv.Add(0);
            for (int k = 0; k <= target; k++)
            {
                if (k == 0)
                {
                    f[i, k] = true;
                }
                else
                {
                    f[i, k] = false;
                }
            }
        }

        //Calc
        for (int i = 0; i < candidates.Length; ++i)
        {
            if (i == 0)
            {
                for (int k = 0; k <= target; ++k)
                {
                    int remainder = k;
                    if (remainder % candidates[i] == 0)
                    {
                        f[i, k] = true;
                    }
                }
            }
            else
            {
                for (int j = 0; j <= target; j++)
                {
                    for (int k = j; k <= target; ++k)
                    {
                        int remainder = k - j;
                        if (remainder % candidates[i] == 0)
                        {
                            f[i, k] = f[i, k] || f[i - 1, j];
                        }
                    }
                }
            }

        }

        // Get Solution
        RecursiveGetCombinations(dCands - 1, target, f, answer, cpv);
        return answer;

    }
    public static int Main()
    {
        Solution s = new Solution();
        var p = s.CombinationSum([2], 1);
        foreach (var ent in p)
        {
            StringBuilder sb = new StringBuilder();
            foreach (var k in ent)
            {
                sb.Append(k);
                sb.Append(" ");
            }
            Console.WriteLine(sb.ToString());
        }

        return 0;
    }
}
