using System;

public class Solution
{

    public bool IsPalindrome(string s)
    {
        bool legalFlag = true;
        int left = 0, right = s.Length - 1;
        while (true)
        {
            while (left < right && !((s[left] >= '0' && s[left] <= '9') || (s[left] >= 'a' && s[left] <= 'z') || ((s[left] >= 'A' && s[left] <= 'Z'))))
            {
                left++;
            }
            while (right > left && !((s[right] >= '0' && s[right] <= '9') || (s[right] >= 'a' && s[right] <= 'z') || ((s[right] >= 'A' && s[right] <= 'Z'))))
            {
                right--;
            }
            if (left >= right)
            {
                break;
            }
            else
            {
                char lx = s[left];
                char rx = s[right];
                if (lx >= 'a' && lx <= 'z')
                {
                    lx = (char)(lx - (char)32);
                }
                if (rx >= 'a' && rx <= 'z')
                {
                    rx = (char)(rx - (char)32);
                }
                if (lx != rx)
                {
                    legalFlag = false;
                    break;
                }
            }
            left++;
            right--;
        }
        return legalFlag;
    }
    public static int Main()
    {
        Solution sol = new Solution();
        while (true)
        {
            var x = Console.ReadLine();
            var p = sol.IsPalindrome(x);
            Console.WriteLine(p);
        }
    }
}