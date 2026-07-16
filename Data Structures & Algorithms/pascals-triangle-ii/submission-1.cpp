class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};

        vector<int> cur = {1};
        vector<int> prev = getRow(rowIndex - 1);

        for (int i = 0; i < prev.size() - 1; i++) {
            cur.push_back(prev[i] + prev[i + 1]);
        }

        cur.push_back(1);

        return cur;
    }
};