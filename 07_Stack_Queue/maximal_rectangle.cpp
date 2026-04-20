/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Maximal Rectangle

🧠 Intuition:
- Convert each row into a histogram:
      • If cell == '1' → increase height
      • If cell == '0' → reset height
- For every row:
      👉 Solve Largest Rectangle in Histogram
- Keep track of maximum area.

⚙️ Approach:
1. Maintain height array (v[]) for histogram.
2. For each row:
      - Update heights
      - Call helper function to compute max histogram area
3. Return maximum area.

⏱️ Time Complexity: O(n * m)
📦 Space Complexity: O(m)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:

    // Helper: Largest Rectangle in Histogram
    int f(vector<int>& v) {

        int n = v.size();
        stack<int> st, st2;

        vector<int> lo(n, -1), hi(n, n);

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && v[st.top()] >= v[i]) {
                st.pop();
            }
            if (!st.empty()) lo[i] = st.top();
            st.push(i);
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && v[st2.top()] >= v[i]) {
                st2.pop();
            }
            if (!st2.empty()) hi[i] = st2.top();
            st2.push(i);
        }

        // Compute max area
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int width = hi[i] - lo[i] - 1;
            maxi = max(maxi, v[i] * width);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        vector<int> v(m, 0); // histogram heights

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '0') v[j] = 0;
                else v[j]++;
            }

            ans = max(ans, f(v));
        }

        return ans;
    }
};