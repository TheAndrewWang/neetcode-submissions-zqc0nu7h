class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<long> memo = {0, 1, 2};
        for (int i = 3; i <= n; i++) {
            memo.push_back(memo[i - 1] + memo[i - 2]);
        }
        return memo[n];

    }
};
