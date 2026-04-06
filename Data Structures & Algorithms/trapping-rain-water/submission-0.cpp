class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftHeight = height[0];
        int rightHeight = height[right];
        int water = 0;
        while (left < right) {
            if (leftHeight > rightHeight) {
                right--;
                if (height[right] > rightHeight) {
                    rightHeight = height[right];
                }
                water += rightHeight - height[right];
            } else {
                left++;
                if (height[left] > leftHeight) {
                    leftHeight = height[left];
                }
                water += leftHeight - height[left];
            }
        }
        return water;
    }
};
