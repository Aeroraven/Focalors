public class Solution
{
    public bool CanPartition(int[] nums)
    {
        int sum = 0;
        foreach (var x in nums) sum += x;
        if (sum % 2 != 0) return false;
        sum /= 2;
        bool[] f = new bool[sum + 1];
        f[0] = true;
        foreach (var x in nums)
        {
            for (int i = sum; i >= 0; i--)
            {
                if (x + i <= sum) f[x + i] = f[x + i] | f[i];
            }
        }
        return f[sum];
    }
}