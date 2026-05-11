/*
===========================================================
📌 Problem: Number of Provinces (LeetCode 547)

🧠 Intuition:
- Connected cities form one province.
- Use BFS to visit all connected cities.

⚙️ Approach:
1. Convert matrix into adjacency list.
2. Traverse graph using BFS.
3. Count every new BFS call as one province.

⏱️ Time Complexity: O(N²)

📦 Space Complexity: O(N²)

===========================================================
*/

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isc) {

        // Adjacency list
        vector<vector<int>> adj(isc.size());

        // Convert matrix to graph
        for (int i = 0; i < isc.size(); i++) {

            for (int j = 0; j < isc[i].size(); j++) {

                if (isc[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;

        // Visited array
        vector<int> vis(isc.size(), 0);

        // BFS traversal
        for (int i = 0; i < vis.size(); i++) {

            if (vis[i] == 0) {

                queue<int> q;
                q.push(i);

                vis[i] = 1;

                while (!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {

                        if (vis[it] == 0) {

                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }

                // One province found
                ans++;
            }
        }

        return ans;
    }
};