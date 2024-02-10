class Solution {
public:
    int iceBreakingGame(int num, int target) {
        int ret = 0;
        for (int i = 1; i <= num; i++) {
            ret = (ret + target) % i;
        }
        return ret;
    }
};