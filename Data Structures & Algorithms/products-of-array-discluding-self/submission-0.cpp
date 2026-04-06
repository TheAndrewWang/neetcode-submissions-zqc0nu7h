class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixes;
        vector<int> postfixes;
        vector<int> output;

        int prod = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefixes.push_back(prod);
            prod *= nums[i];
        }
        prod = 1;
        for (int j = nums.size()-1; j >= 0; j--) {
            postfixes.insert(postfixes.begin(), prod);
            prod *= nums[j];
        }
        for (int k = 0; k < nums.size(); k++) {
            output.push_back(prefixes[k] * postfixes[k]);
        }

        return output;
    }
};
