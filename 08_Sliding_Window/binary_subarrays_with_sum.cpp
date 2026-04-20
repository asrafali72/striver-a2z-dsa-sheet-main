/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Binary Subarrays With Sum

🧠 Intuition:
- Count subarrays with sum = goal.
- Trick:
      count(sum == goal) = count(sum ≤ goal) - count(sum ≤ goal-1)
- Use sliding window to count subarrays with sum ≤ goal.

⚙️ Approach:
1. Create helper function f(nums, goal):
      - Counts subarrays with sum ≤ goal.
2. Use sliding window:
      - Expand right
      - Shrink when sum > goal
      - Add (window size) to answer
3. Final answer:
      f(goal) - f(goal-1)

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:

    // Count subarrays with sum ≤ goal
    int f(vector<int>& nums, int goal) {

        if (goal < 0) return 0;

        int lo = 0, sum = 0, ans = 0;

        for (int hi = 0; hi < nums.size(); hi++) {

            sum += nums[hi];

            // Shrink window if sum exceeds goal
            while (sum > goal) {
                sum -= nums[lo];
                lo++;
            }

            // Add all valid subarrays ending at hi
            ans += (hi - lo + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return f(nums, goal) - f(nums, goal - 1);
    }
};