/*
Problem: Word Search

Platform: LeetCode

Short Explanation:
- Given a 2D board and a word, check if the word exists in the grid.
- The word can be formed by adjacent cells (up, down, left, right).
- Each cell can be used only once in a path.
- Use backtracking (DFS):
    - Start from each cell matching first character.
    - Explore all 4 directions.
    - Mark visited cells temporarily.
    - Backtrack after exploring.

Time Complexity: O(n * m * 4^L)   // L = length of word
Space Complexity: O(L)            // recursion stack
*/

class Solution {
public:

    bool f(int i, int j, int idx,
           vector<vector<char>>& board, string& word) {

        // All characters matched
        if (idx == word.size()) return true;

        // Boundary + mismatch check
        if (i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx]) return false;

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found =
            f(i + 1, j, idx + 1, board, word) ||
            f(i - 1, j, idx + 1, board, word) ||
            f(i, j + 1, idx + 1, board, word) ||
            f(i, j - 1, idx + 1, board, word);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start DFS if first character matches
                if (board[i][j] == word[0] &&
                    f(i, j, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};