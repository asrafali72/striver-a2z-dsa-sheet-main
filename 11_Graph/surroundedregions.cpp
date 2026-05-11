/*
===========================================================
📌 Problem: Surrounded Regions (LeetCode 130)

🧠 Intuition:
- 'O' connected to boundary cannot be captured.
- Mark all boundary connected 'O' cells first.
- Convert remaining 'O' into 'X'.

⚙️ Approach:
1. Traverse boundary cells.
2. Run BFS for every boundary 'O'.
3. Mark visited boundary regions as 'a'.
4. Convert:
      - Remaining 'O' -> 'X'
      - 'a' -> 'O'

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    // BFS traversal
    void f(vector<vector<char>>& bo, int j, int i) {

        queue<pair<int,int>> q;

        q.push({j,i});

        bo[j][i] = 'a';

        while (!q.empty()) {

            auto [a,b] = q.front();
            q.pop();

            // Up
            if (0 <= a-1 && bo[a-1][b] == 'O') {

                q.push({a-1,b});

                bo[a-1][b] = 'a';
            }

            // Down
            if (a+1 < bo.size() && bo[a+1][b] == 'O') {

                q.push({a+1,b});

                bo[a+1][b] = 'a';
            }

            // Left
            if (0 <= b-1 && bo[a][b-1] == 'O') {

                q.push({a,b-1});

                bo[a][b-1] = 'a';
            }

            // Right
            if (b+1 < bo[0].size() && bo[a][b+1] == 'O') {

                q.push({a,b+1});

                bo[a][b+1] = 'a';
            }
        }

        return;
    }

    void solve(vector<vector<char>>& bo) {

        // Traverse top and bottom boundary
        for (int i = 0; i < bo[0].size(); i++) {

            int j = 0;

            if (bo[j][i] == 'O') {
                f(bo, j, i);
            }

            j = bo.size() - 1;

            if (bo[j][i] == 'O') {
                f(bo, j, i);
            }
        }

        // Traverse left and right boundary
        for (int j = 0; j < bo.size(); j++) {

            int i = 0;

            if (bo[j][i] == 'O') {
                f(bo, j, i);
            }

            i = bo[0].size() - 1;

            if (bo[j][i] == 'O') {
                f(bo, j, i);
            }
        }

        // Convert cells
        for (int i = 0; i < bo.size(); i++) {

            for (int j = 0; j < bo[0].size(); j++) {

                if (bo[i][j] == 'O') {
                    bo[i][j] = 'X';
                }

                if (bo[i][j] == 'a') {
                    bo[i][j] = 'O';
                }
            }
        }

        return;
    }
};