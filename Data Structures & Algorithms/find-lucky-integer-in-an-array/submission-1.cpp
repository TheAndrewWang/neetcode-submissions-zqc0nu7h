class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> hi;
        for (int i = 0; i < arr.size(); i++) {
            hi[arr[i]]++;
        }

        int res = -1;
        for (const auto& n : hi) {
            if (n.first == n.second) {
                res = max(n.first, res);
            }
        }
        return res;
    }
};