
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public void Swap(ref int a, ref int b)
    {
        int t = b;
        b = a;
        a = t;
    }
    public void SortColors(int[] a)
    {
        // Use two pointers Pa and Pb to store the position to swap 0 / 2 with other colors
        // Before starting the algorithm, set Pa to the leftmost position and Pb to the rightmost position
        // When a[i] equals to 0, swap it with a[Pa+1] and Pa++
        // When a[i] equals to 2, swap it with a[Pb-1] and Pb--
        // After swapping numbers, if a[i]==1 or (a[i]==0 and i==Pa), i++
        // Terminate the scan when i==Pb or i==a.Length
        // This sort the array within a single O(n) scan.

        int i = 0, pa = -1, pb = a.Length;
        while (!(i == pb || i == a.Length))
        {
            if (a[i] == 0)
            {
                Swap(ref a[pa + 1], ref a[i]);
                pa++;
            }
            if (a[i] == 2)
            {
                Swap(ref a[pb - 1], ref a[i]);
                pb--;
            }
            if ((a[i] == 0 && i <= pa) || a[i] == 1)
            {
                i++;
            }
        }
    }
    public static int Main()
    {
        Solution s = new Solution();
        int[] p = [1, 2, 2, 2, 0, 1, 1, 0];
        s.SortColors(p);
        foreach (var x in p)
        {
            Console.Write(x + ",");
        }
        return 0;
    }
}
