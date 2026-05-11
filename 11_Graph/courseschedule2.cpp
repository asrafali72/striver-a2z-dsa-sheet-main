/*
===========================================================
📌 Problem: Course Schedule II (LeetCode 210)

🧠 Intuition:
- Courses and prerequisites form a directed graph.
- We need to find a valid order to complete courses.
- Use Topological Sorting (Kahn’s Algorithm).

⚙️ Approach:
1. Create adjacency list and indegree array.
2. Push all nodes with indegree 0 into queue.
3. Perform BFS:
      - Remove node
      - Add to answer
      - Reduce indegree of neighbours
4. If all nodes are processed:
      -> return valid order
   Else:
      -> return empty vector

⏱️ Time Complexity: O(V + E)

📦 Space Complexity: O(V + E)

===========================================================
*/

class Solution {
public:

    vector<int> findOrder(int numc, vector<vector<int>>& pre) {

        // Indegree array
        vector<int> v(numc, 0);

        // Adjacency list
        vector<vector<int>> adj(numc);

        // Build graph
        for (auto i : pre) {

            v[i[0]]++;

            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;

        vector<int> ans;

        // Push nodes with indegree 0
        for (int i = 0; i < numc; i++) {

            if (v[i] == 0) {
                q.push(i);
            }
        }

        // BFS traversal
        while (!q.empty()) {

            int a = q.front();
            q.pop();

            ans.push_back(a);

            for (auto i : adj[a]) {

                v[i]--;

                if (v[i] == 0) {
                    q.push(i);
                }
            }
        }

        // Cycle check
        for (int i : v) {

            if (i != 0) {
                return {};
            }
        }

        return ans;
    }
};