using System;

public class Solution
{
    public int MyAtoi(string s)
    {
        bool startRead = false;
        bool isNegative = false;
        long result = 0;
        for (int i = 0; i < s.Length; i++)
        {
            // Leading Substring
            if (!startRead)
            {
                if (s[i] == ' ')
                {
                    continue;
                }
                else if (s[i] == '+')
                {
                    startRead = true;
                    isNegative = false;
                }
                else if (s[i] == '-')
                {
                    startRead = true;
                    isNegative = true;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    startRead = true;
                    i--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                //Process Number
                if (s[i] >= '0' && s[i] <= '9')
                {
                    result = result * 10 + (s[i] - '0');
                    if (result > 0x7fffffff && !isNegative)
                    {
                        result = 0x7fffffff;
                    }
                    if (result > 0x80000000L && isNegative)
                    {
                        result = 0x80000000L;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        if (isNegative)
        {
            result = -result;
        }
        return (int)result;
    }
    public static int Main()
    {
        Solution s = new Solution();
        while (true)
        {
            string? w = Console.ReadLine();
            if (w != null)
            {
                Console.WriteLine(s.MyAtoi(w));
            }
        }
        return 0;
    }
}
