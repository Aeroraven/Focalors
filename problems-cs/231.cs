public class Solution
{
    public bool IsPowerOfTwo(int n)
    {
        if (n <= 0) return false;
        for (int i = 0; i <= 31; i++)
        {
            if ((n & (1 << i)) == n)
            {
                return true;
            }
        }
        return false;
    }
}