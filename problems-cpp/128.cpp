#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>

class Solution {
public:
    std::vector<int> parent;
    std::unordered_map<int,int> hashTable;

    int setFind(int idx) {
        int p = idx;
        while (parent[p] != p) {
            p = parent[p];
        }
        int a = idx;
        while (a != p) {
            int n = parent[a];
            parent[a] = p;
            a = n;
        }
        return p;
    }

    bool insertNumber(int x) {
        if (!hashTable.count(x)) {
            auto w = parent.size();
            hashTable[x] = w;
            parent.push_back(w);

            if (hashTable.count(x - 1)) {
                auto parentLeft = setFind(hashTable[x - 1]);
                parent[parentLeft] = w;
            }
            if (hashTable.count(x + 1)) {
                auto parentRight = setFind(hashTable[x + 1]);
                parent[parentRight] = w;
            }
            return true;
        }
        return false;

    }

    int longestConsecutive(std::vector<int>& nums) {
        std::vector<int> stat(nums.size());
        std::vector<int> val(nums.size());

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!insertNumber(nums[i])) {
                val[i] = -1;
            }
        }
       
        for (int i = 0; i < nums.size(); i++) {
            if (val[i] == -1) {
                continue;
            }
            auto x = nums[i];
            auto belong = setFind(hashTable[x]);
            auto& ref = stat[belong];
            ref += 1;
            if(ref>ans){
                ans = ref;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> p = { 0,3,7,2,5,8,4,6,0,1 };
    std::cout << s.longestConsecutive(p);
    return 0;
}