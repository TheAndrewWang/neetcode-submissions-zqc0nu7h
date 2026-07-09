class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxBananas = max(maxBananas, piles[i]);
        }

        int low = 1; int high = maxBananas; int res = high;
        while (low <= high) {
            int m = (high + low)/2;
            
            long long totalTime = 0;
            for (int i = 0; i < piles.size(); i++) {
                totalTime += ceil(static_cast<double>(piles[i]) / m);
            }

            if (totalTime > h) {
                low = m + 1;
            } else {
                res = m;
                high = m - 1;
            }
        }

        return res;
    }
};
