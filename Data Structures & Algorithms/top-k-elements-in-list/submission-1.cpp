class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int> answers;
        for (int i = 0; i < k; i++) {
            pair<int, int> longestStreak = make_pair(0, 0);
            for (pair<int, int> p : m) {
                if (p.second > longestStreak.second) {
                    longestStreak.first = p.first;
                    longestStreak.second = p.second;
                }
            }
            m[longestStreak.first] = 0;
            answers.push_back(longestStreak.first);
        }
        
        return answers;
    }
};
 