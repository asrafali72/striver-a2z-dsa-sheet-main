/*
===========================================================
📌 Problem: Number of Islands (LeetCode 200)

🧠 Intuition:
- Connected land cells form one island.
- Use BFS to visit all connected land cells.
- Count every new BFS call as one island.

⚙️ Approach:
1. Traverse the grid.
2. If land cell ('1') is found:
      - Increase island count.
      - Run BFS to mark connected land visited.
3. Return total islands.

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        // 4 Directions
        vector<int> dir = {0,1,0,-1,0};

        // Traverse grid
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                // New island found
                if (grid[i][j] == '1') {

                    ans++;

                    queue<pair<int,int>> q;

                    q.push({i,j});

                    // Mark visited
                    grid[i][j] = '0';

                    // BFS traversal
                    while (!q.empty()) {

                        auto [r,c] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int nr = r + dir[k];
                            int nc = c + dir[k+1];

                            // Valid land cell
                            if (nr >= 0 && nr < m &&
                                nc >= 0 && nc < n &&
                                grid[nr][nc] == '1') {

                                q.push({nr,nc});

                                // Mark visited
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};