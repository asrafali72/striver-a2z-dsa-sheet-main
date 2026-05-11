/*
===========================================================
📌 Problem: Rotting Oranges (LeetCode 994)

🧠 Intuition:
- Rotten oranges spread rot to adjacent fresh oranges.
- Use BFS to process oranges level by level.
- Each BFS level represents 1 minute.

⚙️ Approach:
1. Push all rotten oranges into queue.
2. Count fresh oranges.
3. Perform BFS in 4 directions.
4. Convert fresh oranges into rotten.
5. Count minutes required.

⏱️ Time Complexity: O(N × M)

📦 Space Complexity: O(N × M)

===========================================================
*/

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int ans = 0;
        int fresh = 0;

        // 4 Directions
        vector<pair<int,int>> v;

        v.push_back({0,-1});
        v.push_back({-1,0});
        v.push_back({0,1});
        v.push_back({1,0});

        queue<pair<int,int>> q;

        // Store rotten oranges
        // Count fresh oranges
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // BFS traversal
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            ans++;

            for (int i = 0; i < size; i++) {

                auto [a,b] = q.front();
                q.pop();

                for (auto [c,d] : v) {

                    int k1 = a + c;
                    int k2 = b + d;

                    // Check valid fresh orange
                    if (0 <= k1 && k1 < grid.size() &&
                        0 <= k2 && k2 < grid[0].size() &&
                        grid[k1][k2] == 1) {

                        grid[k1][k2] = 2;

                        q.push({k1,k2});

                        fresh--;
                    }
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};