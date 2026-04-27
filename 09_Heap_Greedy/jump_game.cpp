/*
===========================================================
📌 Problem: Jump Game (LeetCode 55)

🧠 Intuition:
- Each element tells max jump length from that position.
- Track the maximum reachable distance while iterating.
- If at any point index > reachable → can't proceed.

⚙️ Approach:
1. Maintain variable `maxReach`
      → farthest index we can reach so far
2. Traverse array:
      - If i > maxReach → return false
      - Update maxReach = max(maxReach, i + nums[i])
3. If traversal completes → return true

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If current index is not reachable
            if (i > maxReach) return false;

            // Update farthest reachable index
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};