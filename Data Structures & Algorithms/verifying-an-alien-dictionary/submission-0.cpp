class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alpha;
        for (int i = 0; i < order.size(); i++) {
            alpha.insert({order[i], i});
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string firstWord = words[i];
            string secondWord = words[i + 1];

            for (int j = 0; j < firstWord.size(); j++) {
                if (j >= secondWord.size()) {
                    return false;
                }
                if (firstWord[j] != secondWord[j]) {
                    if (alpha[firstWord[j]] > alpha[secondWord[j]]) {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};