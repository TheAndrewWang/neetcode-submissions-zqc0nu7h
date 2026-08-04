class Solution {
public:
    double myPow(double x, int n) {
        double result = helper(x, abs(n));        
        if (n < 0) {
            return 1/result;
        }
        return result;
    }

    double helper(double x, int n) {
        if (x == 0) return 0;
        if (x == 1 || n == 0) return 1;
        
        double res = helper(x, floor(n / 2));
        res *= res;
        if (n % 2 == 1) {
            res *= x;
        }
        return res;
    }
};
