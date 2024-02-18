#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string numberConversion(int num, const char* suffix) {
        int part = num % 1000;
        int last = num % 100;
        int hundreds = part / 100;
        if (part == 0) {
            return "";
        }

        string answer = "";
        constexpr static const char* lvMaps[] = {"",
            "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
            "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
        };
        constexpr static const char* hvMaps[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        bool reqSpace = false;
        if (hundreds > 0) {
            answer += lvMaps[hundreds];
            answer += " Hundred";
            reqSpace = true;
        }
        if (last <= 19 && last>0) {
            if (reqSpace) {
                answer += " ";
            }
            answer += lvMaps[last];
        }
        else if (last>0){
            if (reqSpace) {
                answer += " ";
            }
            answer += hvMaps[last / 10];
            if (last % 10 != 0) {
                answer += " ";
                answer += lvMaps[last % 10];
            }
        }
        if (suffix != nullptr) {
            answer += " ";
            answer += suffix;
        }
        return answer;
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        string answer = "";
        bool reqSpace = false;

        constexpr static const char* ctMaps[] = { "Billion","Million","Thousand",nullptr };
        constexpr static const int lim[] = { 1000000000,1000000,1000,1 };

        for (int i = 0; i < 4; i++) {
            int curn = (num / lim[i]) % 1000;
            if (curn != 0) {
                if (reqSpace) {
                    answer += " ";
                }
                answer += numberConversion(curn, ctMaps[i]);
                reqSpace = true;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    while (true) {
        int x;
        cin >> x;
        cout << s.numberToWords(x) << endl;
    }
    return 0;
}