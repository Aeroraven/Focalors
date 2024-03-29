using System;

public class Solution
{
    public int MinimumAddedCoins(int[] coins, int target)
    {
        Array.Sort(coins);
        int curRight = 0;
        int ans = 0;
        for (int i = 0; i < coins.Length; i++)
        {
            if (curRight >= target)
            {
                break;
            }
            while (coins[i] > curRight + 1)
            {
                ans++;
                curRight += (curRight + 1);
            }
            curRight += coins[i];
        }
        while (target > curRight)
        {
            ans++;
            curRight += (curRight + 1);
        }
        return ans;
    }

    static int Main()
    {
        int[] coins = [1, 4, 10, 5, 7, 19];
        Solution s = new Solution();
        Console.WriteLine(s.MinimumAddedCoins(coins, 3));
        return 0;
    }
}