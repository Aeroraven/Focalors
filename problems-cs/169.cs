public class Solution
{
    public int MajorityElement(int[] nums)
    {
        int x = nums[0], cnt = 1;
        for (int i = 1; i < nums.Length; i++)
        {
            if (cnt == 0)
            {
                x = nums[i];
                cnt = 1;
                continue;
            }
            if (x == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return x;
    }
}