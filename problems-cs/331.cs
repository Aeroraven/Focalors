using System.Collections.Generic;
using System;

public class Solution
{
    public bool IsValidSerialization(string preorder)
    {
        if (preorder.Length == 1 && preorder[0] == '#') return true;

        Stack<int> s = new Stack<int>();
        bool first = true;
        for (int i = 0; i < preorder.Length; i++)
        {
            if (preorder[i] == '#')
            {
                i++;
                if (s.Count == 0) return false;
                var p = s.Pop();
                p++;
                if (p != 2) s.Push(p);
            }
            else
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    if (s.Count == 0) return false;
                    var p = s.Pop();
                    p++;
                    if (p != 2) s.Push(p);
                }
                while (i < preorder.Length && preorder[i] != ',')
                {
                    i++;
                }
                s.Push(0);
            }
        }
        return s.Count == 0;
    }
    static int Main()
    {
        Solution s = new Solution();
        string x = "1,2,#,#,#";
        Console.WriteLine(s.IsValidSerialization(x));
        return 0;
    }
}