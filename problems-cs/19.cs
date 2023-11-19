
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
    public ListNode? RemoveNthFromEnd(ListNode head, int n)
    {
        int curStep = 0;
        ListNode? slowCur = head;
        ListNode? fastCur = head;
        while (fastCur.next != null)
        {
            curStep++;
            fastCur = fastCur.next;
            if (curStep > n)
            {
                slowCur = slowCur.next;
            }
        }
        // Remove node at slowCur's next
        if (n == 1 && curStep == 0)
        {
            return null;
        }
        else if (curStep + 1 == n)
        {
            return head.next;
        }
        else if (n > curStep + 1)
        {
            return head;
        }
        else
        {
            fastCur = slowCur.next;
            slowCur.next = fastCur.next;
            return head;
        }
    }

    public static int Main()
    {
        Solution s = new Solution();
        ListNode a5 = new ListNode(5, null);
        ListNode a4 = new ListNode(4, a5);
        ListNode a3 = new ListNode(3, a4);
        ListNode a2 = new ListNode(2, a3);
        ListNode a1 = new ListNode(1, a2);
        var p = s.RemoveNthFromEnd(a2, 4);

        for (ListNode h = p; h != null; h = h.next)
        {
            Console.WriteLine(h.val + "");
        }

        return 0;
    }
}
