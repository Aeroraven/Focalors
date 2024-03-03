using System.Collections.Generic;

public class MyQueue
{
    public Stack<int> s1, s2;
    public MyQueue()
    {
        this.s1 = new Stack<int>();
        this.s2 = new Stack<int>();
    }

    public void Push(int x)
    {
        this.s1.Push(x);
    }

    public int Pop()
    {
        if (this.s2.Count == 0)
        {
            while (s1.Count > 0)
            {
                s2.Push(s1.Pop());
            }
        }
        return s2.Pop();
    }

    public int Peek()
    {
        if (this.s2.Count == 0)
        {
            while (s1.Count > 0)
            {
                s2.Push(s1.Pop());
            }
        }
        return s2.Peek();
    }

    public bool Empty()
    {
        return s1.Count == 0 && s2.Count == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Peek();
 * bool param_4 = obj.Empty();
 */