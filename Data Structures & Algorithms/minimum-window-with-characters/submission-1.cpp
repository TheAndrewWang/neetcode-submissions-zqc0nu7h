class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> collectT, window;
        int have = 0;
        
        for (int i = 0; i < t.size(); i++) {
            collectT[t[i]]++;
        }
        int need = collectT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (collectT.count(c) && window[c] == collectT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (collectT.count(s[l]) && window[s[l]] < collectT[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
