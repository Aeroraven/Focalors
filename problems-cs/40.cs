
using System.Collections.Generic;
using System;
using System.Text;

public class Solution
{
    public int dTargets = 0;
    public int dCands = 0;
    public int stTop = 0;

    public List<int> uniCandidates = new List<int>();
    public List<int> numCandidates = new List<int>();
    public void RecursiveGetCombinations(int curPos, int curCap, bool[,] dv, IList<IList<int>> solution, IList<int> curPlace)
    {
        if (curPos == -1)
        {
            // Add answer here
            List<int> list = new List<int>();
            for (int i = 0; i < uniCandidates.Count; i++)
            {
                for (int j = 0; j < curPlace[i]; j++)
                {
                    list.Add(uniCandidates[i]);
                }
            }
            solution.Add(list);
            return;
        }
        if (curPos == 0)
        {
            if ((curCap - 0) % this.uniCandidates[curPos] == 0)
            {
                curPlace[curPos] = (curCap - 0) / this.uniCandidates[curPos];
                if (curPlace[curPos] > this.numCandidates[curPos]) return;
                RecursiveGetCombinations(curPos - 1, 0, dv, solution, curPlace);
            }
            return;
        }

        for (int i = 0; i <= this.numCandidates[curPos]; i++)
        {
            if (curCap - i * this.uniCandidates[curPos] < 0) return;
            if (dv[curPos - 1, curCap - i * this.uniCandidates[curPos]] == false) continue;
            curPlace[curPos] = i;
            RecursiveGetCombinations(curPos - 1, curCap - i * this.uniCandidates[curPos], dv, solution, curPlace);
        }

    }
    public IList<IList<int>> CombinationSum2(int[] candidates, int target)
    {
        Array.Sort(candidates);
        for (int i = 0; i < candidates.Length; i++)
        {
            if (i == 0 || candidates[i] != candidates[i - 1])
            {
                this.uniCandidates.Add(candidates[i]);
                this.numCandidates.Add(1);
            }
            else
            {
                this.numCandidates[this.numCandidates.Count - 1]++;
            }
        }

        dTargets = target;
        bool[,] f = new bool[this.uniCandidates.Count, target + 1];
        IList<IList<int>> answer = new List<IList<int>>();
        IList<int> cpv = new List<int>();

        //Init
        for (int i = 0; i < this.uniCandidates.Count; i++)
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
        for (int i = 0; i < this.uniCandidates.Count; ++i)
        {
            if (i == 0)
            {
                for (int k = 0; k <= this.numCandidates[i]; ++k)
                {
                    if (k * this.uniCandidates[i] > target) break;
                    f[i, k * this.uniCandidates[i]] = true;
                }
            }
            else
            {
                for (int j = 0; j <= target; j++)
                {
                    if (f[i - 1, j] == false)
                    {
                        continue;
                    }

                    for (int k = 0; k <= this.numCandidates[i]; k++)
                    {
                        if (j + k * this.uniCandidates[i] > target) break;
                        f[i, j + k * this.uniCandidates[i]] = true;
                    }
                }
            }
        }

        // Get Solution
        RecursiveGetCombinations(this.uniCandidates.Count - 1, target, f, answer, cpv);
        return answer;

    }
    public static int Main()
    {
        Solution s = new Solution();
        var p = s.CombinationSum2([1, 2, 4], 5);
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
