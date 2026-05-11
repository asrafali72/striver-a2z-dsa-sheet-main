/*
===========================================================
📌 Problem: Shortest Path in Binary Matrix (LeetCode 1091)

🧠 Intuition:
- Find shortest path from top-left to bottom-right.
- Move allowed in 8 directions.
- Use BFS because every move has equal weight.

⚙️ Approach:
1. If starting cell is blocked -> return -1.
2. Start BFS from (0,0).
3. Traverse all 8 directions.
4. Mark visited cells.
5. Return shortest distance when destination is reached.

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // Start blocked
        if (grid[0][0] != 0) {
            return -1;
        }

        // Single cell case
        if (0 == grid.size()-1 &&
            0 == grid[0].size()-1 &&
            grid[0][0] == 0) {

            return 1;
        }

        queue<pair<int,int>> q;

        q.push({0,0});

        int ans = 0;

        // Visited matrix
        vector<vector<int>> vis(
            grid.size(),
            vector<int>(grid[0].size(), 0)
        );

        // 8 Directions
        vector<vector<int>> idx = {
            {0,-1},
            {0,1},
            {-1,0},
            {1,0},
            {-1,-1},
            {1,1},
            {-1,1},
            {1,-1}
        };

        vis[0][0] = -1;

        // BFS traversal
        while (!q.empty()) {

            int size = q.size();

            ans++;

            while (size--) {

                auto [i,j] = q.front();
                q.pop();

                for (auto k : idx) {

                    int a = i + k[0];
                    int b = j + k[1];

                    // Valid cell
                    if (0 <= a && a < grid.size() &&
                        0 <= b && b < grid[0].size()) {

                        // Unvisited path cell
                        if (vis[a][b] != -1 &&
                            grid[a][b] == 0) {

                            // Destination reached
                            if (a == grid.size()-1 &&
                                b == grid[0].size()-1) {

                                return ans + 1;
                            }

                            q.push({a,b});

                            vis[a][b] = -1;
                        }
                    }
                }
            }
        }

        return -1;
    }
};