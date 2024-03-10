using System;
using System.Text;

public class Solution
{
    public string CapitalizeTitle(string title)
    {
        int n = title.Length;
        StringBuilder sb = new StringBuilder();
        bool lastSpace = true;
        for (int i = 0; i < n; i++)
        {
            if (((title[i] >= 'a' && title[i] <= 'z') || (title[i] >= 'A' && title[i] <= 'Z')) && lastSpace)
            {
                bool validWord = true;
                if (i == n - 1 || i == n - 2)
                {
                    validWord = false;
                }
                else
                {
                    var p1 = title[i + 1];
                    var p2 = title[i + 2];
                    if (p1 == ' ' || p2 == ' ') validWord = false;
                }

                if (validWord && (title[i] >= 'a' && title[i] <= 'z'))
                {
                    sb.Append((char)(title[i] - 'a' + 'A'));
                }
                else if (!validWord && (title[i] >= 'A' && title[i] <= 'Z'))
                {
                    sb.Append((char)(title[i] - 'A' + 'a'));
                }
                else
                {
                    sb.Append(title[i]);
                }

                lastSpace = false;
            }
            else if (title[i] >= 'A' && title[i] <= 'Z' && !lastSpace)
            {
                sb.Append((char)(title[i] - 'A' + 'a'));
                lastSpace = false;
            }
            else if (title[i] == ' ')
            {
                sb.Append(' ');
                lastSpace = true;
            }
            else
            {
                sb.Append(title[i]);
                lastSpace = false;
            }
        }
        return sb.ToString();
    }

    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.CapitalizeTitle("i lOve leetcode LeetCode zz Aa Zz Aa aA x F For for zAx ff pF sCp AAxvA DA da dA"));
        return 0;
    }
}