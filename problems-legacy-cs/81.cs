//SUBOPTIMAL SOLUTION
public class Solution
{
    public bool Search(int[] nums, int target)
    {
        int Len = nums.Length;
        int offset = 0;
        for (int i = 1; i < Len; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                offset = i;
                break;
            }
        }
        for (int i = offset; i < offset + Len; i++)
        {
            if (target > nums[i % Len] && target < nums[(i + 1) % Len] && i != offset + Len)
            {
                break;
            }
            if (target == nums[i % Len])
            {
                return true;
            }
        }
        return false;
    }
}