
using System;

public class Solution
{
    public int NumDecodings(string s)
    {
        int[] f = new int[s.Length];
        for (int i = 0; i < s.Length; i++)
        {
            //Use f[i-1]
            if (s[i] > '0')
            {
                if (i - 1 >= 0)
                {
                    f[i] += f[i - 1];
                }
                else
                {
                    f[i] += 1;
                }
            }
            if (i > 0 && ((s[i - 1] == '1') || (s[i - 1] == '2' && (s[i] >= '0' && s[i] <= '6'))))
            {
                if (i - 2 >= 0)
                {
                    f[i] += f[i - 2];
                }
                else
                {
                    f[i] += 1;
                }
            }
        }
        return f[s.Length - 1];
    }
    public static int Main()
    {
        Solution s = new Solution();
        var p = s.NumDecodings("66");
        Console.WriteLine(p);
        return 0;
    }
}