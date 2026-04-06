class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> block1;
        unordered_map<char, int> block2;
        unordered_map<char, int> block3;
        for (size_t i = 0; i < board.size(); i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> column;
            for (size_t j = 0; j < board[i].size(); j++){
                if (board[i][j] != '.') {
                    row[board[i][j]]++;
                    if (j < 3) {
                        block1[board[i][j]]++;
                    } else if (j > 5) {
                        block3[board[i][j]]++;
                    } else {
                        block2[board[i][j]]++;
                    }
                }
                if (board[j][i] != '.')
                    column[board[j][i]]++;
            }
            auto row_itr = row.begin();
            auto column_itr = column.begin();
            while (row_itr != row.end() && column_itr != column.end()) {
                if (row_itr->second > 1) {
                    return false;
                }
                if (column_itr->second > 1) {
                    return false;
                }
                row_itr++;
                column_itr++;
            }
            if (i == 2 || i == 5 || i == 8 ) {
                auto itr3 = block1.begin();
                auto itr4 = block2.begin();
                auto itr5 = block3.begin();
                while (itr3 != block1.end()) {
                    cout << itr3->first << " sig" << itr3->second << endl;
                    if (itr3->second > 1) {
                        return false;
                    }
                    itr3++;
                }
                while (itr4 != block2.end()) {
                    cout << itr4->first << " ma" << itr4->second << endl;
                    if (itr4->second > 1) {
                        return false;
                    }
                    itr4++;
                }
                while (itr5 != block3.end()) {
                    cout << itr5->first << " boy" << itr5->second << endl;
                    if (itr5->second > 1) {
                        return false;
                    }
                    itr5++;
                }
                // if (i == 2) {
                //     cout << "top" << endl;
                // } else if (i == 5) {
                //     cout << "middle" << endl;
                // } else {
                //     cout << "bottom" << endl;
                // }
                block1.clear();
                block2.clear();
                block3.clear();
            }
        }
        return true;
    }
};
