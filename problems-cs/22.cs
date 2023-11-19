
using System.Collections.Generic;
using System;
using System.Text;

public class Solution
{
	public void RecursiveGeneration(int n, int usedLeft, int usedRight, StringBuilder sb, IList<string> answer)
	{

		int currentPos = usedLeft + usedRight;
		if (usedLeft == usedRight && usedLeft == n)
		{
			answer.Add(sb.ToString());
		}
		if (usedLeft < n)
		{
			sb[currentPos] = '(';
			RecursiveGeneration(n, usedLeft + 1, usedRight, sb, answer);
		}
		if (usedRight < usedLeft)
		{
			sb[currentPos] = ')';
			RecursiveGeneration(n, usedLeft, usedRight + 1, sb, answer);
		}
	}
	public IList<string> GenerateParenthesis(int n)
	{
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n * 2; i++)
		{
			sb.Append("(");
		}
		List<string> answer = new List<string>();
		RecursiveGeneration(n, 0, 0, sb, answer);
		return answer;
	}

	public static int Main()
	{
		Solution s = new Solution();
		var x = s.GenerateParenthesis(3);
		foreach (var item in x)
		{
			Console.WriteLine(item);
		}
		return 0;
	}
}
