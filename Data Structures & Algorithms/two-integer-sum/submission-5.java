class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> differences = new HashMap<>();
        int[] res = {0, 0};

        for (int i = 0; i < nums.length; i++) {
            if (differences.get(nums[i]) != null) {
                res[0] = differences.get(nums[i]);
                res[1] = i;
                return res;
            }

            differences.put(target - nums[i], i);
        }

        return res;

    }
}
