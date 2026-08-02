class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
        
    }

    bool dfs(const vector<vector<char>>& board, const string& word, int r, int c, int i) {

        if (i == word.length()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i] || visited.contains({r, c})) {
            return false;
        }

        visited.insert({r, c});
        bool res = (dfs(board, word, r + 1, c, i + 1) 
        || dfs(board, word, r - 1, c, i + 1) 
        || (dfs(board, word, r, c + 1, i + 1) 
        || (dfs(board, word, r, c - 1, i + 1))));
        visited.erase({r, c});

        return res;
    }
};
