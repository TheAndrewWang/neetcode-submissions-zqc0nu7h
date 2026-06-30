class Solution {
public:

    int characterReplacement(string s, int k) {
        unordered_map<char, int> letters;
        int maxLength = 0;
        int l = 0, maxV = 0;

        for (int r = 0; r < s.size(); r++) {
            letters[s[r]]++;
            maxV = max(maxV, letters[s[r]]);

            if ((r - l + 1) - maxV > k) {
                letters[s[l]]--;
                l++;
            }

            maxLength = max(r - l + 1, maxLength);
        }
        

        return maxLength;
    }
};
