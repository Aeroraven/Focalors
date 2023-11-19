

using System.Collections.Generic;
using System.Text;

public class Solution
{
    public string[] dict = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    public void RecursiveFind(string digits, int curLevel, StringBuilder sb, IList<string> answer)
    {
        if (curLevel == digits.Length)
        {
            answer.Add(sb.ToString());
        }
        else
        {
            int idx = digits[curLevel] - '2';
            for (int i = 0; i < dict[idx].Length; i++)
            {
                sb[curLevel] = this.dict[idx][i];
                this.RecursiveFind(digits, curLevel + 1, sb, answer);
            }
        }
    }
    public IList<string> LetterCombinations(string digits)
    {
        StringBuilder sb = new StringBuilder(digits, digits.Length);
        List<string> answer = new List<string>();
        if (digits.Length > 0)
        {
            RecursiveFind(digits, 0, sb, answer);
        }
        return answer;

    }

    public static int Main()
    {
        Solution s = new Solution();
        s.LetterCombinations("2");
        return 0;
    }
}
