class Solution {
public:
    bool isValid(string s) {
        stack<char> items;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                items.push(s[i]);
                continue;
            }
            if (s[i] == ')') {
                if (items.empty() || items.top() != '(') {
                    return false;
                }
            }
            if (s[i] == '}') {
                if (items.empty() || items.top() != '{') {
                    return false;
                }
            }
            if (s[i] == ']') {
                if (items.empty() || items.top() != '[') {
                    return false;
                }
            }
            items.pop();
        }
        if(!items.empty()) {
            return false;
        }
        return true;
    }
};
