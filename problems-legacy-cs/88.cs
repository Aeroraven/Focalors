public class Solution
{
    public void Merge(int[] nums1, int m, int[] nums2, int n)
    {
        if (m == 0 && n == 0) return;
        int[] num3 = new int[m + n];
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                num3[k++] = nums1[i++];
            }
            else
            {
                num3[k++] = nums2[j++];
            }
        }
        while (i < m)
        {
            num3[k++] = nums1[i++];
        }
        while (j < n)
        {
            num3[k++] = nums2[j++];
        }
        for (int t = 0; t < m + n; t++)
        {
            nums1[t] = num3[t];
        }

    }
}