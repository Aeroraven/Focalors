#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wL = static_cast<int>(words.size());
        vector<string> ans;
        int last = 0;
        int accWords = 0;

        for (int i = 0; i < wL; i++) {
            int totlWidth = accWords + max(i - last -1,0);
            int nextWidth = accWords + words[i].size() + max((i - last), 1);
            if (nextWidth > maxWidth) {
                int reqSpace = maxWidth - accWords;
                int wsqSpace = reqSpace / max(i-last-1,1);
                int rmnSpace = reqSpace % max(i-last-1,1);
                cout << reqSpace << "," << wsqSpace << "," << rmnSpace << endl;
                string s = "";
                for (int j = last; j < i; j++) {
                    s += words[j];
                    if (last == i - 1 && j==last) {
                        //Only one words in the line
                        for (int k = 0; k < reqSpace; k++) {
                            s += ' ';
                        }
                    }
                    else if (j < i - 1) {
                        for (int k = 0; k < wsqSpace; k++) {
                            s += ' ';
                        }
                        if (j - last < rmnSpace) {
                            s += ' ';
                        }
                    }
                }
                if (s != "") {
                    ans.push_back(s);
                }
                last = i;
                accWords = 0;
            }
            accWords += words[i].size();
        }

        //For last line
        string w;
        int wt = 0;
        for (int i = last; i < wL; i++) {
            w += words[i];
            wt += words[i].size();
            if (i != wL - 1) {
                w += ' ';
                wt += 1;
            }
        }
        for (int i = wt; i < maxWidth; i++) {
            w += ' ';
        }
        ans.push_back(w);
        return ans;

    }
};

int main() {
    Solution s;
    int n, k;
    cin >> n >> k;
    vector<string> a;
    string b;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a.push_back(b);
    }
    vector<string> w = s.fullJustify(a,k);
    for (int i = 0; i < w.size(); i++) {
        cout << w[i] << "|" << endl;
    }
	return 0;
}