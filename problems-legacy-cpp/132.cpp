class Solution {
public:
    int minCut(string s) {
        return funct2(s);
    }
    int qmin(int a, int b)
    {
        return (a > b) ? b : a;
    }
    int funct2(std::string a)
    {
        int sz = a.size();
        if (!sz)
        {
            return 0;
        }
        bool** ispdr = new bool* [sz];
        int* f = new int[sz];
        for (int i = 0; i < sz; i++)
        {
            ispdr[i] = new bool[sz];
            for (int j = 0; j < sz; j++)
            {
                ispdr[i][j] = true;
            }
        }
        for (int i = sz - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < sz; j++)
            {
                ispdr[i][j] = (a[i] == a[j]) & ispdr[i + 1][j - 1];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < sz; i++)
        {
            f[i] = (!ispdr[0][i]) ? INT_MAX : 0;
            for (int j = 0; j < i; j++)
            {
                if (ispdr[j + 1][i])
                {
                    f[i] = (f[j] + 1 < f[i]) ? f[j] + 1 : f[i];
                }
            }
        }
        return f[sz - 1];

    }
};