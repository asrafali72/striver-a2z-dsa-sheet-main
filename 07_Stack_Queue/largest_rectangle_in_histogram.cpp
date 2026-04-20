/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Largest Rectangle in Histogram

🧠 Intuition:
- For each bar, find the maximum width where it is the smallest height.
- Width = (next smaller index - previous smaller index - 1)
- Area = height[i] * width
- Use monotonic stack to find:
      • Next Smaller Element (right boundary)
      • Previous Smaller Element (left boundary)

⚙️ Approach:
1. Compute next smaller indices (hi[]).
2. Compute previous smaller indices (lo[]).
3. For each index:
      area = height[i] * (hi[i] - lo[i] - 1)
4. Track maximum area.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& he) {

        int n = he.size();
        stack<int> st;

        vector<int> lo(n, -1), hi(n, n);

        // Step 1: Next Smaller Element (right)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && he[st.top()] >= he[i]) {
                st.pop();
            }
            if (!st.empty()) {
                hi[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Step 2: Previous Smaller Element (left)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && he[st.top()] >= he[i]) {
                st.pop();
            }
            if (!st.empty()) {
                lo[i] = st.top();
            }
            st.push(i);
        }

        // Step 3: Compute max area
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = hi[i] - lo[i] - 1;
            ans = max(ans, he[i] * width);
        }

        return ans;
    }
};