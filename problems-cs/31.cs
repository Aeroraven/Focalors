

using System;
using System.Text;

public class Solution
{
    public void NextPermutation(int[] nums)
    {
        // 6 5 [3] (4 2 1) -> 6 5 4 1 2 3
        // 6 [2] (5 4 3 1) -> 6 3 1 2 4 5
        // 6 3 1 2 [4] (5) -> 6 3 1 2 5 4
        // 6 3 1 [2] (5 4) -> 6 3 1 4 2 5

        int nL = nums.Length;
        int descendLp = nL - 1;
        while (true)
        {
            if (descendLp == 0) break;
            if (nums[descendLp - 1] < nums[descendLp]) break;
            descendLp--;
        }
        if (descendLp == 0)
        {
            //Sort the array
            Array.Sort(nums);
        }
        else
        {
            int incrPos = descendLp - 1;

            // Find the smallest x that x in subsequence [descendLp,R], x>increPos
            int swapPosition = -1;
            for (int i = descendLp; i < nL; i++)
            {
                if (swapPosition == -1 || (nums[incrPos] < nums[i] && nums[i] < nums[swapPosition]))
                {
                    swapPosition = i;
                }
            }
            // Swap incrPos and x
            int tmp = nums[incrPos];
            nums[incrPos] = nums[swapPosition];
            nums[swapPosition] = tmp;

            // Last sort subsequence [descendLp,R]
            for (int i = descendLp; i < nL - 1; i++)
            {
                int smallestPos = i;
                for (int j = i + 1; j < nL; j++)
                {
                    if (nums[smallestPos] > nums[j])
                    {
                        smallestPos = j;
                    }
                }

                int t = nums[smallestPos];
                nums[smallestPos] = nums[i];
                nums[i] = t;
            }

        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < nL; i++)
        {
            builder.Append(nums[i]);
            if (i != nL - 1)
            {
                builder.Append(',');
            }
        }
        Console.WriteLine(builder.ToString());
    }
    public static int Main()
    {
        Solution s = new Solution();
        s.NextPermutation([9, 8, 7, 5, 6, 4, 3, 2, 2]);

        return 0;
    }
}
