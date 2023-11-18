using System;

public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        Array.Sort(nums);
        int answer = 0x7fffffff, difference = 0x7fffffff;

        for (int i = 1; i < nums.Length; i++)
        {
            int c = i - 1;
            // Ensure  num[i]+num[j]+num[c]>=target while num[i]+num[j]+num[c-1]<target
            for (int j = i + 1; j < nums.Length; j++)
            {
                while (true)
                {
                    if (nums[i] + nums[j] + nums[c] >= target)
                    {
                        if (c > 0 && nums[i] + nums[j] + nums[c - 1] >= target)
                        {
                            c--;
                            continue;
                        }
                    }
                    break;
                }
                int rightAnsw = nums[i] + nums[j] + nums[c];
                int rightDiff = Math.Abs(target - rightAnsw);
                if (rightDiff < difference)
                {
                    //Console.WriteLine("Update Answer=" + nums[i] + "," + nums[j] + "," + nums[c]);
                    difference = rightDiff;
                    answer = rightAnsw;
                }

                if (c > 0)
                {
                    int leftAnsw = nums[i] + nums[j] + nums[c - 1];
                    int leftDiff = Math.Abs(target - leftAnsw);
                    if (leftDiff < difference)
                    {
                        //Console.WriteLine("Update Answer=" + nums[i] + "," + nums[j] + "," + nums[c-1]);
                        difference = leftDiff;
                        answer = leftAnsw;
                    }
                }
            }
        }
        return answer;
    }
    public static int Main()
    {
        Solution s = new Solution();
        int[] tgt = { 0, 0, 0 };
        Console.WriteLine(s.ThreeSumClosest(tgt, 1));
        return 0;
    }
}
