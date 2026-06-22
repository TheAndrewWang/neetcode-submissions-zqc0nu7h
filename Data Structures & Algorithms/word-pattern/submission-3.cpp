class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> wordList;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            wordList.push_back(word);
        }

        if (pattern.length() != wordList.size()) return false;

        unordered_map<char, string> letters;
        unordered_map<string, char> wordsToLetters;

        for (int i = 0; i < pattern.length(); i++) {
            char currentLetter = pattern[i];
            string& currentWord = wordList[i];

            cout << currentLetter << " " << currentWord << endl;

            if (letters.count(currentLetter) && letters[currentLetter] != currentWord) return false;
            if (wordsToLetters.count(currentWord) && wordsToLetters[currentWord] != currentLetter) return false;

            letters[currentLetter] = currentWord;
            wordsToLetters[currentWord] = currentLetter;

        }


        return true;
    }
};