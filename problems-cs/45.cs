using System;

public class Solution
{
    public int Jump(int[] a)
    {
        //45
        int r1 = 0;
        int r2 = 0;
        int step1 = 0;
        int step2 = 1;

        for (int i = 0; i < a.Length; i++)
        {
            if (i <= r1)
            {
                r2 = Math.Max(r2, i + a[i]);
                continue;
            }

            if (i > r1 && i <= r2)
            {
                r1 = r2;
                step1 = step2;
                r2 = i + a[i];
                step2 = step1 + 1;
                continue;
            }

            return -1;
        }
        return step1;
    }

}