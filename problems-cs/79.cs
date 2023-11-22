
using System;

public class Solution
{
    public int r = 0;
    public int c = 0;
    public bool legalFlag = false;
    public bool[,] visited = null;
    public void SearchDfs(char[][] board, string word, int position, int x, int y)
    {
        int[] dx = { x + 1, x - 1, x, x };
        int[] dy = { y, y, y + 1, y - 1 };
        if (position == word.Length - 1)
        {
            legalFlag = true;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (legalFlag)
            {
                break;
            }
            if (dx[i] >= 0 && dx[i] < r && dy[i] >= 0 && dy[i] < c)
            {
                if (board[dx[i]][dy[i]] == word[position + 1] && !visited[dx[i], dy[i]])
                {
                    visited[dx[i], dy[i]] = true;
                    SearchDfs(board, word, position + 1, dx[i], dy[i]);
                    visited[dx[i], dy[i]] = false;
                }
            }

        }
    }
    public bool Exist(char[][] board, string word)
    {
        this.r = board.Length;
        this.c = board[0].Length;
        visited = new bool[r, c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i, j] = true;
                    SearchDfs(board, word, 0, i, j);
                    if (legalFlag) { return true; }
                    visited[i, j] = false;
                }
            }
        }
        return false;
    }
    public static int Main()
    {
        Solution s = new Solution();
        char[][] w = [['A', 'B']];
        string p = "ABC";
        Console.WriteLine(s.Exist(w, p));
        return 0;
    }
}

