class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> first = {0, 0};
        vector<int> second = {0, 0};

        first[0] = nums[0];
        first[1] = max(nums[0], nums[1]);
        second[0] = nums[1];
        second[1] = max(nums[1], nums[2]);

        for(int i = 2; i < nums.size() - 1; i++) {
            first.push_back(max(first[i - 1], first[i - 2] + nums[i]));
        }

        for(int i = 3; i < nums.size(); i++) {
            second.push_back(max(second[i - 2], second[i - 3] + nums[i]));
        }

        return max(first[first.size() - 1], second[second.size() - 1]);
    }
};
