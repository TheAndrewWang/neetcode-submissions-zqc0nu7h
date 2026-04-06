class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mostVolume = 0;
        int i = 0;
        int j = heights.size() - 1;
        while (i < j) {
            int sum = (j - i) * min(heights[i], heights[j]);
            if (sum > mostVolume) {
                mostVolume = sum;
            }
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return mostVolume;
    }
};
