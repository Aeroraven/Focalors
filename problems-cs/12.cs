
using System;
using System.Text;

public class Solution
{
    public string IntToRoman(int num)
    {
        char[] chars = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '?' };
        char[] comc = { 'I', 'X', 'C', '?' };
        int mods = 1000;
        int pos = 3;
        StringBuilder sb = new StringBuilder();
        while (true)
        {
            int div = num / mods;
            int rem = div / 5;
            if (div == 4 || div == 9)
            {
                sb.Append(comc[pos]);
                sb.Append(chars[2 * pos + rem + 1]);
            }
            else
            {
                if (rem > 0)
                {
                    sb.Append(chars[2 * pos + 1]);
                }
                for (int i = 0; i < div - rem * 5; i++)
                {
                    sb.Append(chars[2 * pos]);
                }
            }

            num %= mods;
            mods /= 10;
            pos--;

            if (num == 0)
            {
                break;
            }

        }
        return sb.ToString();
    }

    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.IntToRoman(1994));
        Console.WriteLine(s.IntToRoman(58));
        Console.WriteLine(s.IntToRoman(9));
        Console.WriteLine(s.IntToRoman(4));
        return 0;
    }
}
