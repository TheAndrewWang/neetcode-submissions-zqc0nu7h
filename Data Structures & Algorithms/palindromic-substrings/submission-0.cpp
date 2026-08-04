class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            helper(res, i, i, s);
            if (i < s.size() - 1) {
                helper(res, i, i + 1, s);
            }
        }
        return res;
        
    }

    void helper(int& res, int l, int r, const string& s) {
        if (l < 0 || r >= s.size() || s[l] != s[r]) {
            return; 
        }

        res++;
        helper(res, l - 1, r + 1, s);
    }
};
