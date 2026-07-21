class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; int r = 0;
        unordered_set<char> letters;
        int maxLength = 0;

        while (r < s.size()) {
            maxLength = max(maxLength, r - l);
            while (letters.contains(s[r])) {
                letters.erase(s[l]);
                l++;
            }
            letters.insert(s[r]);
            
            r++;
        }
        maxLength = max(maxLength, r - l);

        return maxLength;
    }
};
