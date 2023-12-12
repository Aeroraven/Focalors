public class Solution
{
    public int RemoveDuplicates(int[] w)
    {
        int len = w.Length;
        int deleted = 0;
        int cnt = 1;
        int j = 1;
        for (int i = 1; i < len; i++)
        {

            //Console.WriteLine(i);
            if (w[i] == w[i - 1])
            {
                //Console.WriteLine("A");
                if (cnt < 2)
                {
                    cnt++;
                    w[j] = w[i];
                    j++;
                    //Console.WriteLine("A1");
                }
                else
                {
                    w[j] = w[i];
                    deleted++;
                    //Console.WriteLine("A2");
                }
            }
            else
            {
                //Console.WriteLine("B");
                cnt = 1;
                w[j] = w[i];
                j++;
            }
        }
        //Console.WriteLine(len);
        //Console.WriteLine(deleted);
        return len - deleted;
    }
}