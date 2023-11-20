using System.Text;

public class Solution
{
    public string Multiply(string a, string b)
    {
        //43
        int aL = a.Length;
        int bL = b.Length;
        int[] res = new int[aL + bL + 1];
        for (int i = 0; i < bL; i++)
        {
            // Multiply
            int[] rp = new int[aL + 1];
            int pb = bL - 1 - i;
            int carry = 0;
            for (int j = 0; j < aL; j++)
            {
                int pa = aL - 1 - j;
                int prod = (a[pa] - '0') * (b[pb] - '0') + carry;
                carry = prod / 10;
                prod = prod % 10;
                rp[j] = prod;
            }
            rp[aL] = carry;

            //Add
            carry = 0;
            for (int j = 0; j <= aL; j++)
            {
                res[j + i] += rp[j] + carry;
                carry = res[j + i] / 10;
                res[j + i] %= 10;
            }
        }
        StringBuilder sb = new StringBuilder();
        bool prz = true;
        for (int i = aL + bL - 1; i >= 0; i--)
        {
            if (prz && res[i] == 0)
            {
                continue;
            }
            if (prz && res[i] != 0)
            {
                prz = false;
            }
            sb.Append(res[i]);
        }
        if (prz)
        {
            return "0";
        }
        return sb.ToString();
    }
}