class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(res, 0, nums, subset);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, int i, const vector<int>& nums, vector<int> subset) {
        if (i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        dfs(res, i + 1, nums, subset);
        subset.push_back(nums[i]);
        dfs(res, i + 1, nums, subset);
    }
};
