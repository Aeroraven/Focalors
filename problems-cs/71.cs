
using System.Collections.Generic;
using System;
using System.Text;


public class Solution
{

    public string SimplifyPath(string path)
    {
        //It's obvious that we should use stack to maintain the directory structure
        Stack<string> stack = new Stack<string>();
        StringBuilder sb = new StringBuilder();

        int curLen = 0, curDots = 0;
        bool lastSlash = true;
        path = path + "/";
        for (int i = 0; i < path.Length; i++)
        {
            if (path[i] == '/')
            {
                if (!lastSlash)
                {
                    if (curLen == 2 && curDots == 2)
                    {
                        if (stack.Count > 0) stack.Pop();
                    }
                    else if (curLen == 1 && curDots == 1)
                    {
                        //Do nothing
                    }
                    else
                    {
                        stack.Push(sb.ToString());
                    }
                    curLen = 0;
                    curDots = 0;
                    sb.Clear();
                }
                lastSlash = true;
            }
            else
            {
                lastSlash = false;
                curLen++;
                if (path[i] == '.')
                {
                    curDots++;
                }
                sb.Append(path[i]);
            }
        }

        //Construct Path
        var p = stack.ToArray();
        sb.Clear();
        if (p.Length == 0)
        {
            return "/";
        }
        for (int i = p.Length - 1; i >= 0; i--)
        {
            sb.Append('/');
            sb.Append(p[i]);
        }
        return sb.ToString();

    }
    public static int Main()
    {
        Solution s = new Solution();
        while (true)
        {
            string w = Console.ReadLine();
            Console.WriteLine(s.SimplifyPath(w));
        }
        return 0;
    }
}
