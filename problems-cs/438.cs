using System.Collections.Generic;
using System;

public class Solution
{
    public IList<int> FindAnagrams(string s, string p)
    {
        int[] requiredCnt = new int[26];
        int[] recordedCnt = new int[26];
        IList<int> answer = new List<int>();

        int reqMet = 0;

        foreach (var x in p)
        {
            requiredCnt[x - 'a'] += 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (requiredCnt[i] == recordedCnt[i])
            {
                reqMet++;
            }
        }

        // Initialize the window
        int l = 0, r = 0;
        while (r < p.Length && r < s.Length)
        {
            var v = s[r] - 'a';
            if (requiredCnt[v] == recordedCnt[v]) reqMet--;
            recordedCnt[v]++;
            if (requiredCnt[v] == recordedCnt[v]) reqMet++;
            r++;
        }

        // Slide the window
        r--;
        while (r < s.Length)
        {
            if (reqMet == 26)
            {
                answer.Add(l);
            }
            var vl = s[l] - 'a';
            if (requiredCnt[vl] == recordedCnt[vl]) reqMet--;
            recordedCnt[vl]--;
            if (requiredCnt[vl] == recordedCnt[vl]) reqMet++;
            l++;

            r++;
            if (r >= s.Length) break;
            var vr = s[r] - 'a';
            if (requiredCnt[vr] == recordedCnt[vr]) reqMet--;
            recordedCnt[vr]++;
            if (requiredCnt[vr] == recordedCnt[vr]) reqMet++;
        }

        return answer;
    }

    public static int Main()
    {
        Solution s = new Solution();
        string sx = "a";
        string p = "aa";
        var x = s.FindAnagrams(sx, p);
        foreach (var i in x)
        {
            Console.WriteLine(i);
        }
        return 0;
    }
}