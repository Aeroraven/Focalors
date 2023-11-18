using System.Collections.Generic;
using System;

public int Divide(int dividend, int divisor)
{
    long a = Math.Abs((long)dividend);
    long b = Math.Abs((long)divisor);
    bool negative = (dividend < 0) ^ (divisor < 0);
    List<long> baseMp = new List<long>(); //Stores [b*1,b*2,...b*p], subjects b*p <= a while b*(p+p)>a
    List<long> baseBp = new List<long>(); //Stores [1,2,4,...,p]
    long bmp = b, bbp = 1;
    for (int i = 1; ; i++)
    {
        if (bmp > a) break;
        baseMp.Add(bmp);
        baseBp.Add(bbp);

        bmp += bmp;
        bbp += bbp;
    }
    long remain = a;
    long answer = 0;
    for (int i = baseMp.Count - 1; i >= 0; i--)
    {
        if (remain >= baseMp[i])
        {
            remain -= baseMp[i];
            answer += baseBp[i];
        }
    }
    if (negative)
    {
        answer = -answer;
    }
    if (answer > 0x7fffffffL)
    {
        answer = 0x7fffffffL;
    }
    if (answer < -0x80000000L)
    {
        answer = -0x80000000L;
    }
    return (int)answer;
}