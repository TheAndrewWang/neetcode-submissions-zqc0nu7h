class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp;
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (m.count(diff) && m[diff] != i) {
                return {i, m[diff]};
            }
        }
        return {};
    }
};
