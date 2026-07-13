class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size() - 1;
        while (l < h) {
            int m = (h + l)/2;
            if (nums[m] < nums[h]) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        if (nums[l] > nums[0]) {
            return nums[0];
        }
        return nums[l];
    }
};
