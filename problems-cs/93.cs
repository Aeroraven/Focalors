using System.Collections.Generic;
using System.Text;
using System;

public class Solution
{
    public IList<string> answer = new List<string>();
    public int[] pos = new int[4];
    public void Dfs(string s, int ord)
    {
        if (ord == 4)
        {
            if (pos[3] != s.Length - 1)
            {
                return;
            }
            int lp = -1;
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < 4; i++)
            {
                string k = s.Substring(lp + 1, pos[i] - lp);
                stringBuilder.Append(k);
                if (i != 3)
                {
                    stringBuilder.Append('.');
                }
                lp = pos[i];
            }
            answer.Add(stringBuilder.ToString());
            return;
        }
        int lastPos = -1;
        if (ord > 0)
        {
            lastPos = pos[ord - 1];
        }

        bool firstDigit = true;
        int nums = 0;
        for (int i = lastPos + 1; i < s.Length; i++)
        {
            if (firstDigit && s[i] == '0')
            {
                pos[ord] = i;
                Dfs(s, ord + 1);
                return;
            }
            firstDigit = false;
            nums = nums * 10 + (s[i] - '0');
            if (nums > 255) return;
            pos[ord] = i;

            Dfs(s, ord + 1);
        }
    }
    public IList<string> RestoreIpAddresses(string s)
    {
        Dfs(s, 0);
        return answer;
    }
    public static int Main()
    {
        while (true)
        {
            Solution s = new Solution();
            var x = Console.ReadLine();
            Console.WriteLine(x);
            var p = s.RestoreIpAddresses(x);
            foreach (var item in p)
            {
                Console.WriteLine(item);
            }
        }


    }
}