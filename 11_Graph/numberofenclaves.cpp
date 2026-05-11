/*
===========================================================
📌 Problem: Number of Enclaves (LeetCode 1020)

🧠 Intuition:
- Land cells connected to boundary
  cannot be enclaves.
- Remove all boundary connected lands.
- Count remaining land cells.

⚙️ Approach:
1. Traverse all boundary cells.
2. Run BFS for every boundary land cell.
3. Mark connected lands as water.
4. Count remaining land cells.

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    // BFS traversal
    void bfs(vector<vector<int>>& grid, int i, int a) {

        queue<pair<int,int>> q;

        q.push({i,a});

        grid[i][a] = 0;

        while (!q.empty()) {

            auto [c,d] = q.front();
            q.pop();

            // Up
            if (0 <= c-1 && grid[c-1][d] == 1) {

                q.push({c-1,d});

                grid[c-1][d] = 0;
            }

            // Left
            if (0 <= d-1 && grid[c][d-1] == 1) {

                q.push({c,d-1});

                grid[c][d-1] = 0;
            }

            // Down
            if (c+1 < grid.size() && grid[c+1][d] == 1) {

                q.push({c+1,d});

                grid[c+1][d] = 0;
            }

            // Right
            if (d+1 < grid[0].size() && grid[c][d+1] == 1) {

                q.push({c,d+1});

                grid[c][d+1] = 0;
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int a = 0;
        int b = grid[0].size() - 1;

        // Traverse left and right boundary
        for (int i = 0; i < grid.size(); i++) {

            if (grid[i][a] == 1) {
                bfs(grid, i, a);
            }

            if (grid[i][b] == 1) {
                bfs(grid, i, b);
            }
        }

        int i = 0;

        b = grid.size() - 1;

        // Traverse top and bottom boundary
        for (int a = 0; a < grid[0].size(); a++) {

            if (grid[i][a] == 1) {
                bfs(grid, i, a);
            }

            if (grid[b][a] == 1) {
                bfs(grid, b, a);
            }
        }

        // Count remaining land cells
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};