class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) continue;
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (nums[j] == nums[j - 1]) {
                        j++;
                    } 
                }
            }
        }           
        
        return output;
    }
};
