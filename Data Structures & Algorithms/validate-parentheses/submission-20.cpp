class Solution {
public:
    bool isValid(string s) {
        stack<char> cache;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                cache.push(s[i]);
                continue;
            }

            if (cache.empty()) return false;

            if (s[i] == ')') {
                if (cache.top() != '(') {
                    return false;
                }
                cache.pop();
            }
            if (s[i] == ']') {
                if (cache.top() != '[') {
                    return false;
                }
                cache.pop();
            }
            if (s[i] == '}') {
                if (cache.top() != '{') {
                    return false;
                }
                cache.pop();
            }
        }
        if (!cache.empty()) return false;
        return true;
    }
};
