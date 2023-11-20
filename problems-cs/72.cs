
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public int MinDistance(string s, string t)
    {
        //Let f[i][j] denote the minimal distance required to:
        // I. change prefix s[0...j] into  t[0...i]
        // II. and be subject to t[i] == s[j]
        // Then
        // f[i][j] = min{f[i-1][k] + (j-k-1)} + !(t[i]==s[j])    (1) Delete & Change
        // f[i][j] = min{f[i-1][j]+1,f[i][j]}                   (2) Insert
        // f[-1,-1] = 0 ,f[k,-1] = k+1, f[-1,k] = k+1
        s = s + "*";
        t = t + "*";
        int[,] f = new int[t.Length, s.Length];
        for (int i = 0; i < t.Length; i++)
        {
            for (int j = 0; j < s.Length; j++)
            {
                f[i, j] = 10000;
            }
        }
        for (int i = 0; i < t.Length; i++)
        {
            for (int j = 0; j < s.Length; j++)
            {
                //Delete & Change
                int v = (t[i] == s[j]) ? 0 : 1;
                for (int k = 0; k < j; k++)
                {
                    if (i == 0)
                    {
                        int x = k + 1;
                        f[i, j] = Math.Min(x + (j - k - 1) + v, f[i, j]);
                    }
                    else
                    {
                        f[i, j] = Math.Min(f[i - 1, k] + (j - k - 1) + v, f[i, j]);
                    }

                }
                f[i, j] = Math.Min(i + j + v, f[i, j]);

                //Insert
                if (i == 0)
                {
                    f[i, j] = Math.Min(j + 1, f[i, j]);
                }
                else
                {
                    f[i, j] = Math.Min(f[i - 1, j] + 1, f[i, j]);
                }

            }
        }
        return f[t.Length - 1, s.Length - 1];
    }
    public static int Main()
    {
        Solution s = new Solution();
        while (true)
        {
            string a = "apple";
            string b = "";
            Console.WriteLine(s.MinDistance(a, b));
        }

        return 0;
    }
}
