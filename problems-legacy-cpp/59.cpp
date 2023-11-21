class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int rows = n;
        int cols = n;
        int matsz = rows * cols;
        int rb = 0, ru = rows - 1, cb = 0, cu = cols - 1;
        int cr = 0, cc = 0;
        int md = 0;
        int wflg = 0;
        int ct = 1;
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++)
        {
            ans.push_back(vector<int>{});
            for (int j = 0; j < cols; j++)
            {
                ans[i].push_back(0);
            }
        }
        while (matsz--)
        {
            if (wflg)wflg = 0;
            else
            {
                ans[cr][cc] = ct;
                ct++;
            }
            switch (md)
            {
            case 0: // ->
                if (cc != cu)cc++;
                else wflg = 1;
                if (cc == cu)
                {
                    md = 1;
                    rb++;
                }
                break;
            case 1: // Down
                if (cr != ru)cr++;
                else wflg = 1;
                if (cr == ru)
                {
                    md = 2;
                    cu--;
                }
                break;
            case 2:
                if (cc != cb) cc--;
                else wflg = 1;
                if (cc == cb)
                {
                    md = 3;
                    ru--;
                }
                break;
            case 3:
                if (cr != rb) cr--;
                else wflg = 1;
                if (cr == rb)
                {
                    md = 0;
                    cb++;
                }
                break;
            }
            if (wflg) matsz++;
        }
        return ans;
    }
};
¿ØÖÆÌ¨
