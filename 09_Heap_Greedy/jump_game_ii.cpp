/*
===========================================================
📌 Problem: Jump Game II (LeetCode 45)

🧠 Intuition:
- We need minimum jumps to reach last index.
- Greedy idea:
      Treat the array like BFS levels (range expansion).
- Each jump extends the reachable boundary.

⚙️ Approach:
1. Maintain:
      - end → current jump boundary
      - farthest → farthest reachable index in current range
      - jumps → number of jumps taken
2. Traverse till n-1:
      - Update farthest = max(farthest, i + nums[i])
      - If i == end:
            → we must jump
            → jumps++
            → end = farthest
3. Return jumps

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;
        int end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            // Update farthest reachable
            farthest = max(farthest, i + nums[i]);

            // When we reach current boundary
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};