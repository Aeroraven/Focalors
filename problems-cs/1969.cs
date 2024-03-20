using System;

public class Solution
{
    long fastPow(long basev, long p, long mod)
    {
        long ret = 1;
        long b = basev;
        while (p > 0)
        {
            if ((p & 1) == 1)
            {
                ret = ret * b;
                ret %= mod;
            }
            b *= b;
            b %= mod;
            p /= 2;
        }
        return ret;
    }
    long fastPow2(long basev, long p, long mod)
    {
        long b = basev;
        long ret = 1;
        for (int i = 0; i < p; i++)
        {
            ret *= b;
            b *= b;
            b %= mod;
            ret %= mod;
        }
        return ret;
    }
    public int MinNonZeroProduct(int p)
    {
        long mod = 1000000007;
        var bx = fastPow(2, p, mod);
        bx = (bx - 2 + mod) % mod;
        var cx = fastPow2(bx, p - 1, mod);
        cx *= (bx + 1);
        cx %= mod;
        return (int)cx;
    }
    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.MinNonZeroProduct(1));
        Console.WriteLine(s.MinNonZeroProduct(2));
        Console.WriteLine(s.MinNonZeroProduct(3));
        Console.WriteLine(s.MinNonZeroProduct(4));
        Console.WriteLine(s.MinNonZeroProduct(5));
        return 0;
    }
}