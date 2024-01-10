using System;

public class Solution
{
    public void MoveZeroes(int[] nums)
    {
        int n = nums.Length;
        int left = 0;
        int fast = 0;
        while (fast < n)
        {
            while (fast < n && nums[fast] == 0)
            {
                fast++;
            }
            if (fast >= n) break;
            nums[left] = nums[fast];
            left++;
            fast++;
        }
        for (int i = left; i < n; i++)
        {
            nums[i] = 0;
        }
    }

    public static int Main()
    {
        Solution solution = new Solution();
        int[] a = [1, 2, 3, 4, 5, 6, 7, 8, 9];
        solution.MoveZeroes(a);

        foreach (var x in a)
        {
            Console.Write(x);
            Console.Write(",");
        }
        return 0;
    }
}