/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Trapping Rain Water

🧠 Intuition:
- Water trapped at any index depends on:
      min(left_max, right_max) - height[i]
- We precompute right_max array and track left_max on the fly.

⚙️ Approach:
1. Create an array hi[] to store right max for each index.
2. Traverse from right → left:
      - Store maximum height seen so far.
3. Traverse from left → right:
      - Maintain left max.
      - Water at i = min(left_max, right_max[i]) - height[i]
4. Add positive water values to answer.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int trap(vector<int>& he) {

        int n = he.size();
        int lo = 0, ans = 0;

        // Step 1: Right max array
        vector<int> hi(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            lo = max(lo, he[i]);
            hi[i] = lo;
        }

        // Step 2: Traverse and calculate water
        lo = 0;

        for (int i = 0; i < n; i++) {

            lo = max(lo, he[i]); // left max

            if (lo > he[i] && he[i] < hi[i]) {
                ans += (min(lo, hi[i]) - he[i]);
            }
        }

        return ans;
    }
};