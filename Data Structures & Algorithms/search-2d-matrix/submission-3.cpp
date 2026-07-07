class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> numbers;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                numbers.push_back(matrix[i][j]);
            }
        } 

        int l = 0;
        int r = numbers.size() - 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (target == numbers[m]) {
                return true;
            }
            if (target < numbers[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
