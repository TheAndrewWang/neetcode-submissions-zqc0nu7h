class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end()); // n log n

            m[sortedString].push_back(strs[i]);
        }
        vector<vector<string> > output;
        for (auto it : m) {
            output.push_back(it.second);
        }
        return output;
    }
};
