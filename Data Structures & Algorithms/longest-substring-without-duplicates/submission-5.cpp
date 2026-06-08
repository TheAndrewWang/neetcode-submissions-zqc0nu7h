class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> chars{};
       string window{};
       size_t maxLength{};
       for (int i{}; i < s.length(); i++) {
            auto it = chars.find(s[i]);
            if (it != chars.end()) {
                int j = 0;
                char target = *it;
                while (window[j] != target) {
                    chars.erase(window[j]);
                    ++j;
                }
                window = window.substr(++j, s.size());
            }
            chars.insert(s[i]);
            window += s[i];
            maxLength = max(maxLength, window.size());
       }
       return maxLength;
    }
};
