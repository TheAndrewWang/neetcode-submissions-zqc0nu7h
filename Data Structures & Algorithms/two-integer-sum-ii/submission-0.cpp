class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> output;
        while (left < right) {
            int currentSum = numbers[left] + numbers[right];
            if (currentSum > target) {
                right--;
            } else if (currentSum < target) {
                left++;
            } else {
                output.push_back(left+1);
                output.push_back(right+1);
                break;
            }
        }
        return output;
        
    }
};
