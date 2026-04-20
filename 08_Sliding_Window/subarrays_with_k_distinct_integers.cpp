/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Subarrays with K Distinct Integers

🧠 Intuition:
- Directly counting exactly k distinct is hard.
- Trick:
      👉 count(exactly k) = count(at most k) - count(at most k-1)
- Use sliding window to count subarrays with at most k distinct.

⚙️ Approach:
1. Create helper f(nums, k):
      - Count subarrays with at most k distinct elements.
2. Use hashmap to track frequency.
3. Expand window (hi), shrink if distinct > k.
4. Add (window size) to result.
5. Final answer:
      f(k) - f(k-1)

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(k)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:

    // Count subarrays with at most k distinct
    int f(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int lo = 0;
        int count = 0;

        for (int hi = 0; hi < nums.size(); hi++) {

            mp[nums[hi]]++;

            // Shrink window if distinct > k
            while (mp.size() > k) {
                mp[nums[lo]]--;
                if (mp[nums[lo]] == 0) {
                    mp.erase(nums[lo]);
                }
                lo++;
            }

            // Add valid subarrays
            count += (hi - lo + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return f(nums, k) - f(nums, k - 1);
    }
};