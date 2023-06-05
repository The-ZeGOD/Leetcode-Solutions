class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
        unordered_set<char> seen;
        for (int j = 0; j < 9; j++) {
            char current = board[i][j];
            if (current != '.') {
                if (seen.find(current) != seen.end()) {
                    return false; // Duplicate value found in the row
                }
                seen.insert(current);
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++) {
        unordered_set<char> seen;
        for (int i = 0; i < 9; i++) {
            char current = board[i][j];
            if (current != '.') {
                if (seen.find(current) != seen.end()) {
                    return false; // Duplicate value found in the column
                }
                seen.insert(current);
            }
        }
    }

    // Check sub-boxes
    for (int box = 0; box < 9; box++) {
        unordered_set<char> seen;
        int rowOffset = (box / 3) * 3;
        int colOffset = (box % 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char current = board[rowOffset + i][colOffset + j];
                if (current != '.') {
                    if (seen.find(current) != seen.end()) {
                        return false; // Duplicate value found in the sub-box
                    }
                    seen.insert(current);
                }
            }
        }
    }

    return true;
    }
};
