class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int h = nums.size() - 1;
        while (l <= h) {
            int m = (h + l) / 2;
            if (nums[m] == target) {
                return m;
            }
            
            if (nums[m] >= nums[l]) {
                if (target < nums[m]) {
                    if (target < nums[l]) {
                        l = m + 1;
                    } else {
                        h = m - 1;
                    }
                } else {
                    l = m + 1;
                }
            } else {
                if (target < nums[m]) {
                    h = m - 1;
                } else {
                    if (target > nums[h]) {
                        h = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            }
        }

        return -1;
        
    }
};
