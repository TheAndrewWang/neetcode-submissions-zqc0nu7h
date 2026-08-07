class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") {
            return 0;
        }

        int l = 0; int r = 1;
        set<char> seen;
        size_t maxLength = 1;
        seen.insert(s[0]);

        while(r < s.size()) {
            if (seen.contains(s[r])) {
                while(s[l] != s[r]) {
                    seen.erase(s[l]);
                    l++;
                }
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            maxLength = max(maxLength, seen.size());
            r++;
        }

        return maxLength;
    }
};
