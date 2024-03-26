using System;

public class Solution
{
    public int CoinChange(int[] coins, int amount)
    {
        int[] f = new int[amount + 1];
        for (int i = 1; i <= amount; i++)
        {
            f[i] = 1000000;
        }
        foreach (var i in coins)
        {
            for (int k = 0; k <= amount; k++)
            {
                f[k] = Math.Min(f[k], f[k - i] + 1);
            }
        }
        if (f[amount] > 900000) return -1;
        return f[amount];
    }
}