class Solution {
public:

    string encode(vector<string>& strs) {
        string tmp = "";
        for (int i = 0; i < strs.size(); i++) {
            tmp += to_string(strs[i].size()) + "-" + strs[i];
        }
        return tmp;
    }

    vector<string> decode(string s) {
        int c = 0;
        string element = "";
        string counter = "";
        vector<string> answer;
        
        for (int i = 0; i < s.size(); i++) {
            if (c == 0) {
                if (s[i] == '-') {
                    c += stoi(counter);
                    if (c == 0) {
                        answer.push_back("");
                    }
                } else {
                    counter += s[i];
                }
            } else {
                element += s[i];
                if (c == 1) {
                    answer.push_back(element);
                    element = "";
                    counter = "";
                }
                c--;
            }
        }
        return answer;
    }
};
