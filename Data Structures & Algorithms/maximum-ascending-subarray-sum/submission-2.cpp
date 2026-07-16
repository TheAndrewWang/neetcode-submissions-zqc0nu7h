class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0]; int cur = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                cur = 0;
                
            } 
            cur += nums[i]; 
            res = max(res, cur);
            
        }
        return res;
    }
};