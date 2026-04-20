/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Sliding Window Maximum

🧠 Intuition:
- We need the maximum element in every window of size k.
- Use a deque to store indices:
      • Maintain decreasing order of values
      • Front always holds the max of current window

⚙️ Approach:
1. Use deque (stores indices, not values).
2. Remove elements from back if smaller than current.
3. Remove front if it goes out of window.
4. Front of deque → maximum for current window.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(k)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> q; // stores indices

        // Step 1: Process first k-1 elements
        for (int i = 0; i < k - 1; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        // Step 2: Process remaining elements
        for (int i = k - 1; i < nums.size(); i++) {

            // Maintain decreasing order
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);

            // Remove elements out of window
            if (q.front() <= i - k) {
                q.pop_front();
            }

            // Current maximum
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};