using System.Text;

public class Solution
{
    public bool IsValidSudoku(char[][] board)
    {
        int[] rowx = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int[] colx = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int[] boxx = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                int p = board[i][j];
                int v = (1 << (p - '0'));
                if (((rowx[i]) & v) > 0)
                {
                    return false;
                }
                if (((colx[j]) & v) > 0)
                {
                    return false;
                }
                int bx = i / 3;
                int by = j / 3;
                int bid = bx * 3 + by;
                if (((boxx[bid]) & v) > 0)
                {
                    return false;
                }

                rowx[i] |= v;
                colx[j] |= v;
                boxx[bid] |= v;
            }
        }
        return true;
    }
    public static int Main()
    {
        Solution s = new Solution();
        return 0;
    }
}
