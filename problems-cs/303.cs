public class NumArray
{
    int[] a;
    public NumArray(int[] nums)
    {
        int n = nums.Length;
        for (int i = 1; i < n; i++) nums[i] += nums[i - 1];
        a = nums;
    }

    public int SumRange(int left, int right)
    {
        return a[right] - (left == 0 ? 0 : a[left - 1]);
    }
}
