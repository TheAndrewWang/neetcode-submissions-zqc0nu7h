class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> letters(26, 0);
            for (char c : strs[i]) {
                letters[c - 'a']++;
            }
            string key;
            for (int l = 0; l < letters.size(); l++) {
                char c = l + 'a';
                key += c + to_string(letters[l]);
            }
            m[key].push_back(strs[i]);
        }
        vector<vector<string> > output;
        for (auto it : m) {
            output.push_back(it.second);
        }
        return output;
    }
};
