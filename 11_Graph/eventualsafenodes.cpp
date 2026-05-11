/*
===========================================================
📌 Problem: Find Eventual Safe States (LeetCode 802)

🧠 Intuition:
- Safe nodes are nodes that do not lead to a cycle.
- Terminal nodes (outdegree 0) are always safe.
- Use reverse graph + Topological Sort.

⚙️ Approach:
1. Reverse all graph edges.
2. Store outdegree of every node.
3. Push terminal nodes into queue.
4. Perform BFS:
      - Remove safe node
      - Reduce outdegree of parent nodes
5. Nodes reaching outdegree 0 become safe.

⏱️ Time Complexity: O(V + E)

📦 Space Complexity: O(V + E)

===========================================================
*/

class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& gr) {

        int n = gr.size();

        // Reverse graph
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < gr[i].size(); j++) {

                adj[gr[i][j]].push_back(i);
            }
        }

        // Store outdegree
        vector<int> vis(n, 0);

        queue<int> q;

        vector<int> ans;

        // Find terminal nodes
        for (int i = 0; i < n; i++) {

            vis[i] = gr[i].size();

            if (vis[i] == 0) {
                q.push(i);
            }
        }

        // BFS traversal
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto i : adj[node]) {

                vis[i]--;

                if (vis[i] == 0) {
                    q.push(i);
                }
            }
        }

        // Return sorted safe nodes
        sort(ans.begin(), ans.end());

        return ans;
    }
};