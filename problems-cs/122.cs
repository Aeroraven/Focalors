using System;

public class Solution
{
    public int MaxProfit(int[] prices)
    {
        //f[i] = a[i]+max(-a[j]+f[k])

        int maxAjFk = -prices[0];
        int maxFk = 0;
        int answer = 0;
        int f = 0;
        for (int i = 1; i < prices.Length; i++)
        {
            f = prices[i] + maxAjFk;
            maxFk = Math.Max(maxFk, f);
            maxAjFk = Math.Max(maxAjFk, maxFk - prices[i]);
            answer = Math.Max(f, answer);
            //Console.WriteLine(i + "," + f);
        }
        return answer;
    }
}