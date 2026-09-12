class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letters;
        for (int i = 0; i < s.size(); i++) { letters[s[i]]++; }

        int lengthOfPalindrome = 0;
        int longestOdd = 0;
        
        for (pair<char, int> p : letters) {
            if (p.second % 2 == 0) {
                lengthOfPalindrome += p.second;
            } else {
                if (longestOdd > 0) {
                    if (longestOdd < p.second) {
                        lengthOfPalindrome += longestOdd - 1;
                        longestOdd = p.second;
                    } else {
                        lengthOfPalindrome += p.second - 1;
                    }
                } else {
                    longestOdd = p.second;
                }
            }
        }

        lengthOfPalindrome += longestOdd;

        return lengthOfPalindrome;
    }
};