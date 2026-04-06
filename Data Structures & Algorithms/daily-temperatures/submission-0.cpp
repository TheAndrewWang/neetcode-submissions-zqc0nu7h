class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size());
        stack<int> indices;
        for (int i{0}; i < temperatures.size(); i++) {
            if(indices.empty() || temperatures[i] <= temperatures[indices.top()]) {
                indices.push(i);
                continue;
            }
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                out[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        while (!indices.empty()) {
            out[indices.top()] = 0;
            indices.pop();
        }
        return out;
    }
};
