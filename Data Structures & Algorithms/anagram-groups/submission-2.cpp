class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > finalOutput;
        unordered_map<string, vector<string> > m;
        for(size_t i = 0; i < strs.size(); i++) {
            vector<int> chars(26, 0);
            for (size_t j = 0; j < strs[i].size(); j++) {
                chars[strs[i][j] - 'a']++;
            }
            string key = "";
            for (size_t k = 0; k < chars.size(); k++) {
                char currentCharacter = (char) k;
                key += currentCharacter + to_string(chars[k]);
            }
            m[key].push_back(strs[i]);
        }
        for (pair<string, vector<string> > pair : m) {
            finalOutput.push_back(pair.second);
        }
        return finalOutput;
    }
};
