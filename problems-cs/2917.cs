using System;

public class Solution
{
	public int FindKOr(int[] nums, int k)
	{
		int n = nums.Length;
		int ret = 0;
		for (int j = 0; j <= 30; j++)
		{
			int counter = 0;
			for (int i = 0; i < n; i++)
			{
				if ((nums[i] & (1 << j)) == (1 << j))
				{
					counter++;
				}
				if (counter >= k)
				{
					ret |= (1 << j);
					break;
				}
			}
		}
		return ret;
	}

	public static int Main()
	{
		Solution solution = new Solution();
		int[] x = [7, 12, 9, 8, 9, 15];
		Console.WriteLine(solution.FindKOr(x, 4));
		return 0;
	}
}