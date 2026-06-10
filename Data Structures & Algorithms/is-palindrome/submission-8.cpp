class Solution {
public:
    bool isPalindrome(string s) {
        string stripped{};
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                stripped += tolower(s[i]);
            }
        }
        int start = 0;
        int end = stripped.size() - 1;
        while (start < end) {
            if (stripped[start] != stripped[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
