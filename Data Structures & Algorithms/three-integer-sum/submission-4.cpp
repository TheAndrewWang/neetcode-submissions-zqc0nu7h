class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans; 
        sort(nums.begin(), nums.end());

        for(unsigned int i = 0; i < nums.size(); i++){
            for(unsigned int j = i + 1; j < nums.size(); j++){
                for(unsigned int k = j + 1; k < nums.size(); k++){
                    if(nums[i] + nums[j] + nums[k] == 0 && i != j && j != k && i != k){
                        vector<int> newans;
                        newans.push_back(nums[i]);
                        newans.push_back(nums[j]);
                        newans.push_back(nums[k]);
                        ans.insert(newans);
                    }
                }
            }
        }

        vector<vector<int>> realans;

        for(vector<int> v : ans) realans.push_back(v);

        return realans; 

    }
};
