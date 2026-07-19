class Solution {
public:
    int climbStairs(int n) {
        int one = 1; int two = 1;
        if (n == 1 || n == 2) {
            return n;
        }
        return dfs(one, two, n - 2);
    }

    int dfs(int one, int two, int i) {
        int res = one + two;
        if (i == 0) {
            return res;
        }
        return dfs(res, one, --i);
    }
};
