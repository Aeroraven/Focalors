public class Solution
{
    public void Swap(ref int a, ref int b)
    {
        int t = b;
        b = a;
        a = t;
    }

    public void Rotate(int[][] m)
    {
        //48


        int r = m.Length;
        int offset = 0;
        //2-1 4-3 6-5
        //3-2 1-0
        for (int i = r; i >= 2; i -= 2)
        {
            for (int j = 0; j < i - 1; j++)
            {
                int[] px = { offset + j, (r - 1) - offset, (r - 1 - offset) - j, offset };
                int[] py = { offset, offset + j, (r - 1) - offset, (r - 1 - offset) - j };
                for (int k = 0; k <= px.Length - 2; k++)
                {
                    Swap(ref m[px[k]][py[k]], ref m[px[k + 1]][py[k + 1]]);
                }
            }

            offset += 1;
        }

    }
}