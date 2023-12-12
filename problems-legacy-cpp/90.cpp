class Solution {
public:
    vector<int> ans;
    vector<int> w;
    set<vector<int>> at;
    vector<vector<int>> g;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        dfs(nums, 0);
        g.assign(at.begin(), at.end());
        return g;
    }
    void dfs(vector<int>& nums, int s) {
        if (s == nums.size()) {
            w.assign(ans.begin(), ans.end());
            sort(w.begin(), w.end());
            at.insert(w);
        }
        else {
            dfs(nums, s + 1);
            ans.push_back(nums[s]);
            dfs(nums, s + 1);
            ans.pop_back();
        }
    }
};