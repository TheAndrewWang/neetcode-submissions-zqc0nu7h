class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // initial variables and stack
        stack<int> numbers;
        bool first {true};

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int temp = numbers.top();
                numbers.pop();
                int temp2 = numbers.top();
                numbers.pop();
                int result;
                if (tokens[i] == "+") {
                    result = temp + temp2;
                } else if (tokens[i] == "-") {
                    result = temp2 - temp;
                } else if (tokens[i] == "*") {
                    result = temp * temp2;
                } else if (tokens[i] == "/") {
                    result = temp2 / temp;
                }
                numbers.push(result);
            } else {
                numbers.push(stoi(tokens[i]));
            }
        }
        return numbers.top();
    }
};
