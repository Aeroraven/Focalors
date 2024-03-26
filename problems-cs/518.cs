public class Solution
{
    public int Change(int amount, int[] coins)
    {
        int[] f = new int[amount + 1];
        f[0] = 1;
        foreach (var i in coins)
        {
            for (int k = i; k <= amount; k++)
            {
                f[k] += f[k - i];
            }
        }
        return f[amount];
    }
}