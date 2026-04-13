/*
Problem: N-Queens

Platform: LeetCode

Short Explanation:
- Place n queens on an n x n chessboard such that no two queens attack each other.
- A queen can attack:
    - Same column
    - Diagonal (left & right)
- Use backtracking:
    - Place one queen per row.
    - Check if position is valid.
    - Recurse for next row.
    - Backtrack if needed.

Time Complexity: O(N!)
Space Complexity: O(N)   // recursion stack
*/

class Solution {
public:

    bool isvalid(int col, int row, vector<string>& board) {

        int j = col;

        // Check column (upwards)
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        // Check right diagonal (↗)
        for (int i = row, c = col; i >= 0 && c < board.size(); i--, c++) {
            if (board[i][c] == 'Q') return false;
        }

        // Check left diagonal (↖)
        for (int i = row, c = col; i >= 0 && c >= 0; i--, c--) {
            if (board[i][c] == 'Q') return false;
        }

        return true;
    }

    void f(int row, int n, vector<string>& board,
           vector<vector<string>>& ans) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isvalid(col, row, board)) {

                // Place queen
                board[row][col] = 'Q';

                // Recurse
                f(row + 1, n, board, ans);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        f(0, n, board, ans);

        return ans;
    }
};