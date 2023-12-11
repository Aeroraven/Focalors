
using System;

public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode Partition(ListNode head, int x)
    {
        ListNode smallerHead = null, smallerTail = null;
        ListNode largerHead = null, largerTail = null;
        ListNode current = head;
        while (current != null)
        {
            ListNode next = current.next;
            if (current.val < x)
            {
                if (smallerHead == null)
                {
                    smallerHead = current;
                    smallerTail = current;
                }
                else
                {
                    smallerTail.next = current;
                    smallerTail = current;
                }
            }
            else
            {
                if (largerHead == null)
                {
                    largerHead = current;
                    largerTail = current;
                }
                else
                {
                    largerTail.next = current;
                    largerTail = current;
                }
            }
            current = next;
        }
        //Merge List
        if (head == null)
        {
            return null;
        }
        if (smallerHead == null)
        {
            largerTail.next = null;
            return largerHead;
        }
        smallerTail.next = largerHead;
        if (largerTail != null)
        {
            largerTail.next = null;
        }
        return smallerHead;

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

