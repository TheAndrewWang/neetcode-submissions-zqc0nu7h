class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> currentNumbers;
        recursion(res, currentNumbers, target, nums);

        return res;
    }

    void recursion(vector<vector<int>>& res, vector<int>& currentNumbers, int target, const vector<int>& nums) {
        int currentSum = 0;
        for (int i = 0; i < currentNumbers.size(); i++) {
            currentSum += currentNumbers[i];
        }

        if (currentSum == target) {
            res.push_back(currentNumbers);
            return;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (!currentNumbers.empty() && nums[i] > currentNumbers.back()) continue;
            if ((currentSum + nums[i]) <= target) {
                currentNumbers.push_back(nums[i]);
                recursion(res, currentNumbers, target, nums);
                currentNumbers.pop_back();
            }
        }
    }
};
