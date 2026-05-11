/*
===========================================================
📌 Problem: 01 Matrix (LeetCode 542)

🧠 Intuition:
- Find shortest distance of every cell
  from nearest 0.
- Use Multi-Source BFS starting from all 0s.

⚙️ Approach:
1. Push all 0 cells into queue.
2. Mark their distance as 0.
3. Perform BFS in 4 directions.
4. Update minimum distance for neighbours.

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // Answer matrix
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));

        queue<pair<int,int>> q;

        // 4 Directions
        vector<vector<int>> idx = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        // Push all 0s into queue
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {

                    q.push({i,j});

                    ans[i][j] = 0;
                }
            }
        }

        // Multi-source BFS
        while (!q.empty()) {

            auto [x,y] = q.front();
            q.pop();

            for (auto k : idx) {

                int nx = x + k[0];
                int ny = y + k[1];

                // Valid cell
                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < m) {

                    // Relax distance
                    if (ans[nx][ny] > ans[x][y] + 1) {

                        ans[nx][ny] = ans[x][y] + 1;

                        q.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};