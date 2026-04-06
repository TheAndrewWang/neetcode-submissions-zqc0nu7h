class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        unordered_map<char, int> m2;
        for (int i = 0; i < s.size(); i++) {
            ++m[s[i]];
            ++m2[t[i]];
        }
        unordered_map<char, int>::iterator itr = m.begin();
        if (s.size() != t.size()) {return false;}
        while (itr != m.end()) {
            if (m2.find(itr->first) == nullptr) {
                return false;
            }
            if (m2.find(itr->first)->second != itr->second) {
                return false;
            }
            itr++;
        }
        return true;
    }
};
