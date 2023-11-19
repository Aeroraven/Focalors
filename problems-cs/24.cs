
using System;
using System.Text;


public class ListNode
{
    public int val;
    public ListNode? next;
    public ListNode(int val = 0, ListNode? next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{

    public ListNode SwapPairs(ListNode head)
    {
        int curPair = 0;
        ListNode newHead = head;
        ListNode? cur = head;
        ListNode tail = head;
        while (true)
        {
            if (cur == null) break;
            if (cur.next == null) break;
            ListNode? nextBegin = cur.next.next;

            //Swap inside the pair
            ListNode first = cur;
            ListNode second = cur.next;
            second.next = first;
            first.next = nextBegin;

            if (curPair == 0)
            {
                newHead = second;
                tail = first;
            }
            else
            {
                tail.next = second;
                tail = first;
            }

            cur = nextBegin;
            curPair++;
        }
        return newHead;
    }
    public static int Main()
    {
        Solution s = new Solution();
        ListNode a6 = new ListNode(6, null);
        ListNode a5 = new ListNode(5, a6);
        ListNode a4 = new ListNode(4, a5);
        ListNode a3 = new ListNode(3, a4);
        ListNode a2 = new ListNode(2, a3);
        ListNode a1 = new ListNode(1, a2);
        var p = s.SwapPairs(a4);

        for (ListNode h = p; h != null; h = h.next)
        {
            Console.WriteLine(h.val + "");
        }

        return 0;
    }
}
