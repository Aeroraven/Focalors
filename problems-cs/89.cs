
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

	public IList<int> GrayCode(int n)
	{
		// Intuition can be obtained by finding the law inside n-bit Gray code sequence
		// N=1: 0 -> 1
		// N=2: 00 01 -> 11 10
		// N=3: 000 001 011 010 -> 110 111 101 100
		// N=4: 0000 0001 0011 0010 0110 0111 0101 0100 -> 1100 ... 1000
		// Then for (n+1)-bit gray code sequence, reverse the n-bit gray code sequence and set the highest bit to 1
		// Append the new list to the tail
		// The correctness can be proved using the recursion procedure:
		// Assume P is a n-bit gray code sequence. 
		// I. Set the (n+1)-bit to 1 still meets the requirement: Adjacent numbers differ exactly by one bit
		// II. P[0] is always zero and P[last] only have 1 in its highest bit.
		// III. P[2^n-1] and P[2^n] only differ exactly by one bit (their highest bit).
		//
		// The complexity of the algorithm is O(2^n) or O(answers)

		IList<int> list = new List<int>();
		list.Add(0);
		list.Add(1);
		int hbit = 2;
		for (int i = 2; i <= n; i++)
		{
			for (int j = hbit - 1; j >= 0; j--)
			{
				list.Add(list[j] | hbit);
			}
			hbit <<= 1;
		}
		return list;
	}
	public static int Main()
	{
		Solution s = new Solution();
		var p = s.GrayCode(4);
		foreach (var x in p)
		{
			Console.WriteLine(x);
		}
		return 0;
	}
}
