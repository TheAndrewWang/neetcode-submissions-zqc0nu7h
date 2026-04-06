class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums;
        int totalSum = 0;
        int subArrays = 0;
        prefixSums[0] = 1;

        for (const int& current : nums) {
            totalSum += current; // add to totalSum
            if (prefixSums[totalSum - k] != NULL) {
                subArrays += prefixSums[totalSum - k];
            }
            prefixSums[totalSum]++; //add prefixSum for the current number
        }
        return subArrays;
    }
};