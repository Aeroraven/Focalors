using System;
using System.Collections;

public class Solution
{
    public int SubarraySum(int[] nums, int k)
    {
        Hashtable hashTable = new Hashtable();
        hashTable.Add(0, 1);

        int psum = 0, ans = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            psum += nums[i];
            int req = psum - k;
            if (hashTable.Contains(req))
            {
                ans += (int)hashTable[req];
            }
            if (hashTable.Contains(psum))
            {
                int c = (int)hashTable[psum];
                hashTable.Remove(psum);
                hashTable.Add(psum, 1 + c);
            }
            else
            {
                hashTable.Add(psum, 1);
            }
        }
        return ans;
    }

    public static int Main()
    {
        Solution solution = new Solution();
        int[] nums = [-1, -1, 1];
        int w = solution.SubarraySum(nums, 2);
        Console.WriteLine(w);
        return 0;
    }
}