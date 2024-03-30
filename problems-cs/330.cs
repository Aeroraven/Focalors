public class Solution
{
    public int MinPatches(int[] nums, int n)
    {
        long curRight = 0;
        int ans = 0;
        foreach (int x in nums)
        {
            if (curRight >= n) break;
            while (x > curRight + 1)
            {
                if (curRight >= n) break;
                ans++;
                curRight += (curRight + 1);
            }
            curRight += x;
        }
        while (n > curRight)
        {
            ans++;
            curRight += (curRight + 1);
        }
        return ans;
    }
}