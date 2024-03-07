using System;

public class Solution
{
    public int MinimumPossibleSum(int n, int target)
    {
        const long MODF = 1000000007;
        long rb = Math.Min(n, (target) / 2);
        long leftAns = (1 + rb) * rb / 2;
        leftAns %= MODF;

        if (rb < n)
        {
            long xb = (n - rb);
            long rightAns = (target + (target + (xb - 1))) * xb / 2;
            leftAns += rightAns;
            leftAns %= MODF;
        }
        return (int)leftAns;
    }

    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.MinimumPossibleSum(1, 1));
        return 0;
    }
}