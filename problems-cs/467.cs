using System;

public class Solution
{
    public int FindSubstringInWraproundString(string s)
    {
        int n = s.Length;
        int[] ans = new int[26];
        int[] f = new int[n];
        f[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if ((s[i] - s[i - 1] + 26) % 26 == 1)
            {
                f[i] = f[i - 1] + 1;
            }
            else
            {
                f[i] = 1;
            }
            ans[s[i]] = Math.Max(ans[s[i]], f[i]);
        }
        int ret = 0;
        foreach (var x in ans) ret += x;
        return ret;
    }
}
