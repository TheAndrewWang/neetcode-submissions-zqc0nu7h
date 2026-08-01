class Solution {
    public int trap(int[] height) {
        int low = 0; int high = height.length - 1;
        int lowMax = height[low]; int highMax = height[high];
        int res = 0;

        while (low < high) {
            if (lowMax <= highMax) {
                low++;
                lowMax = Math.max(lowMax, height[low]);
                res += lowMax - height[low];
            } else {
                high--;
                highMax = Math.max(highMax, height[high]);
                res += highMax - height[high];
            }
        }
        

        return res;
    }
}
