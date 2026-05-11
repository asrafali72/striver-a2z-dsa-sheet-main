/*
===========================================================
📌 Problem: Is Graph Bipartite? (LeetCode 785)

🧠 Intuition:
- A graph is bipartite if we can color
  adjacent nodes with different colors.
- Use BFS coloring technique.

⚙️ Approach:
1. Use color array:
      0 -> unvisited
      1 -> color 1
      2 -> color 2
2. Traverse every component using BFS.
3. Assign alternate colors to neighbours.
4. If two adjacent nodes get same color:
      -> return false

⏱️ Time Complexity: O(V + E)

📦 Space Complexity: O(V)

===========================================================
*/

class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // Color array
        vector<int> v(n, 0);

        // Traverse all components
        for (int i = 0; i < n; i++) {

            if (v[i] != 0) {
                continue;
            }

            queue<int> q;

            v[i] = 1;

            q.push(i);

            // BFS traversal
            while (!q.empty()) {

                int a = q.front();
                q.pop();

                for (auto j : graph[a]) {

                    // If uncolored
                    if (v[j] == 0) {

                        if (v[a] == 1) {
                            v[j] = 2;
                        }
                        else {
                            v[j] = 1;
                        }

                        q.push(j);
                    }

                    // Same color found
                    else if (v[a] == v[j]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};