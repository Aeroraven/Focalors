
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public int[][] Insert(int[][] intervals, int[] newInterval)
    {
        //First find the interval (L) that contains left endpoint of the new segment
        //Then find the right one(R) use the same way.
        //Finally, merge intervals in range [L,R].
        //This will take O(logn) time using binary search algorithm

        //But dmn fvck, add answer always take O(n)!!!!

        int iL = intervals.Length;
        int leftL = 0, rightL = iL - 1;
        while (leftL < rightL)
        {
            int mid = (leftL + rightL) / 2;
            if (intervals[mid][0] > newInterval[0])
            {
                //Here L = rightL
                rightL = mid;
                continue;
            }
            if (intervals[mid][1] < newInterval[0])
            {
                leftL = mid + 1;
                continue;
            }
            if (intervals[mid][0] <= newInterval[0] && intervals[mid][1] >= newInterval[0])
            {
                rightL = mid;
                break;
            }
        }

        int leftR = 0, rightR = iL - 1;
        while (leftR < rightR)
        {
            int mid = (leftR + rightR + 1) / 2;
            if (intervals[mid][1] < newInterval[1])
            {
                //Here R=leftR
                leftR = mid;
            }
            if (intervals[mid][0] > newInterval[1])
            {
                rightR = mid - 1;
            }
            if (intervals[mid][0] <= newInterval[1] && intervals[mid][1] >= newInterval[1])
            {
                leftR = mid;
                break;
            }
        }


        //Scan from [rightL,leftR] to check intervals to merge
        List<int[]> answers = new List<int[]>();
        //Some tricky cases
        if (intervals.Length == 0)
        {
            answers.Add(newInterval);
            return answers.ToArray();
        }
        if (intervals[0][0] > newInterval[1])
        {
            answers.Add(newInterval);
            for (int i = 0; i < iL; i++)
            {
                answers.Add(intervals[i]);
            }
            return answers.ToArray();
        }
        if (intervals[intervals.Length - 1][1] < newInterval[0])
        {

            for (int i = 0; i < iL; i++)
            {
                answers.Add(intervals[i]);
            }
            answers.Add(newInterval);
            return answers.ToArray();
        }
        //Normal cases
        if (rightL <= leftR && rightL >= 0)
        {
            int mergeSt = newInterval[0], mergeEd = newInterval[1];
            mergeSt = Math.Min(mergeSt, intervals[rightL][0]);
            mergeEd = Math.Max(mergeEd, intervals[leftR][1]);

            for (int i = 0; i < rightL; i++)
            {
                answers.Add(intervals[i]);
            }
            int[] tmp = { mergeSt, mergeEd };
            answers.Add(tmp);
            for (int i = leftR + 1; i < iL; i++)
            {
                answers.Add(intervals[i]);
            }
        }
        else
        {
            for (int i = 0; i <= leftR; i++)
            {
                answers.Add(intervals[i]);
            }
            answers.Add(newInterval);
            for (int i = rightL; i < iL; i++)
            {
                answers.Add(intervals[i]);
            }
        }
        return answers.ToArray();

    }

    public static int Main()
    {
        Solution s = new Solution();
        var x = s.Insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [16, 124]);
        foreach (var p in x)
        {
            Console.Write("[" + p[0] + "," + p[1] + "],");
        }
        Console.WriteLine("");
        return 0;
    }
}
