class Solution {
public:
    bool isValidBox(vector<vector<char>>& board, int R, int C) {
        // check bounds
        if (R < 0 || R >= 9 || C < 0 || C >= 9) {
            cout << "out of bounds!" << endl;
            return false;
        }

        // check each 3x3 box
        unordered_set<char> seen;
        for (int r = R; r < R+3; r++) {
            for (int c = C; c < C+3; c++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (seen.find(num) != seen.end()) {
                    // cout << "box invalid!" << endl;
                    return false;
                }
                seen.insert(num);
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (seen.find(num) != seen.end()) {
                    // cout << "row invalid!" << endl;
                    return false;
                }
                seen.insert(num);
            }
        }

        // check cols
        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (seen.find(num) != seen.end()) {
                    // cout << "col invalid!" << endl;
                    return false;
                }
                seen.insert(num);
            }
        }

        // check 3x3 box
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                if (!isValidBox(board, r, c)) {
                    return false;
                }
            }
        }

        return true;
    }
};