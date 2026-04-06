class Solution {
public:
    bool isPalindrome(string s) {
        string parsedString = "";
        for (unsigned int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= 65 && c <= 90) {
                c = s[i] + 32;
            } 
            if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57)) {
                parsedString += c;
            }
        }
        if (parsedString == "")
            return true;
        for (unsigned int x = 0; x < parsedString.size()-x-1; x++) {
            unsigned int y = parsedString.size()-x-1;
            if (parsedString[x] != parsedString[y]) {
                return false;
            }
        }
        return true;
    }
};
