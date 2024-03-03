using System.Collections.Generic;

public class MyStack
{
    public Queue<int> q;
    public MyStack()
    {
        this.q = new Queue<int>();
    }

    public void Push(int x)
    {
        this.q.Enqueue(x);
    }

    public int Pop()
    {
        for (int i = 0; i < this.q.Count - 1; i++)
        {
            var w = this.q.Dequeue();
            this.q.Enqueue(w);
        }
        return this.q.Dequeue();
    }

    public int Top()
    {
        for (int i = 0; i < this.q.Count - 1; i++)
        {
            var w = this.q.Dequeue();
            this.q.Enqueue(w);
        }
        var ans = this.q.First();
        this.q.Dequeue();
        this.q.Enqueue(ans);
        return ans;

    }

    public bool Empty()
    {
        return this.q.Count == 0;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Top();
 * bool param_4 = obj.Empty();
 */