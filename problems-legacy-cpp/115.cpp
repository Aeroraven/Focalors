class Solution {
public:
    int numDistinct(string a, string b) {
        int asz = a.size();
        int bsz = b.size();
        if (bsz > asz)return 0;
        if (asz * bsz == 0)return 0;
        unsigned int* g = new unsigned int[bsz];
        for (int j = 0; j < bsz; j++)
        {
            g[j] = 0;
        }
        for (int i = 0; i < asz; i++)
        {
            int l = (i > bsz) ? bsz : i;
            for (int j = l; j >= 0; j--)
            {
                if (a[i] == b[j] && j != 0)
                {
                    g[j] += g[j - 1];
                }
                else if (a[i] == b[j] && j == 0)
                {
                    g[j]++;
                }
            }
        }
        return g[bsz - 1];
    }
};