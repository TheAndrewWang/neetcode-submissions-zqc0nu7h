class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            auto s = min_element(nums.begin(), nums.end());
            int index = distance(nums.begin(), s);
            nums[index] *= multiplier;
        }   
        return nums;
    }
};