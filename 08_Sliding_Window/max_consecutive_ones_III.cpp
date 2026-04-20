/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Max Consecutive Ones III

🧠 Intuition:
- We can flip at most k zeros → treat them as ones.
- Use sliding window:
      • Expand window (hi)
      • Count zeros used
      • If zeros > k → shrink window (lo)

⚙️ Approach:
1. Traverse array using hi pointer.
2. If nums[hi] == 0 → decrement k.
3. If k < 0 → move lo forward and restore k when needed.
4. Track maximum window size.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int lo = 0, hi = 0;
        int ans = 0;

        while (hi < nums.size()) {

            // Use one flip if zero encountered
            if (nums[hi] == 0) {
                k--;
            }

            // If flips exceeded, shrink window
            while (lo <= hi && k < 0) {
                if (nums[lo] == 0) {
                    k++;
                }
                lo++;
            }

            // Update max length
            ans = max(ans, hi - lo + 1);

            hi++;
        }

        return ans;
    }
};