/*
===========================================================
📌 Problem: Course Schedule (LeetCode 207)

🧠 Intuition:
- Courses and prerequisites form a directed graph.
- If graph contains a cycle,
  all courses cannot be completed.
- Use Topological Sorting (Kahn’s Algorithm).

⚙️ Approach:
1. Create adjacency list.
2. Store indegree of every node.
3. Push nodes with indegree 0 into queue.
4. Perform BFS:
      - Remove node
      - Reduce indegree of neighbours
5. If all nodes are processed:
      -> return true
   Else:
      -> return false

⏱️ Time Complexity: O(V + E)

📦 Space Complexity: O(V + E)

===========================================================
*/

class Solution {
public:

    bool canFinish(int numC, vector<vector<int>>& prerequisites) {

        // Indegree array
        vector<int> vis(numC, 0);

        // Adjacency list
        vector<vector<int>> adj(numC);

        // Build graph
        for (auto it : prerequisites) {

            vis[it[1]]++;

            adj[it[0]].push_back(it[1]);
        }

        queue<int> q;

        // Push nodes with indegree 0
        for (int i = 0; i < numC; i++) {

            if (vis[i] == 0) {
                q.push(i);
            }
        }

        // BFS traversal
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                vis[it]--;

                if (vis[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Check cycle
        for (auto i : vis) {

            if (i != 0) {
                return false;
            }
        }

        return true;
    }
};