using System.Text;

public class Solution
{
    public string GetHint(string secret, string guess)
    {
        int[] count = new int[10];
        int n = secret.Length;
        int bulls = 0, cows = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                count[secret[i] - '0']++;
            }

        }
        for (int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i])
            {
                if (count[guess[i] - '0'] > 0)
                {
                    cows++;
                    count[guess[i] - '0']--;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.Append(bulls);
        sb.Append("A");
        sb.Append(cows);
        sb.Append("B");
        return sb.ToString();
    }
    public static int Main()
    {
        Solution s = new Solution();
        Console.WriteLine(s.GetHint("1123", "0111"));
        return 0;
    }
}