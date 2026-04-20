/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Count Number of Nice Subarrays

🧠 Intuition:
- A "nice subarray" has exactly k odd numbers.
- Convert array:
      odd → 1
      even → 0
- Problem becomes:
      count subarrays with sum = k

⚙️ Approach (Prefix Sum + HashMap):
1. Maintain running sum of odd counts.
2. Use hashmap to store frequency of prefix sums.
3. For each index:
      - Check if (sum - k) exists in map
      - Add its frequency to answer
4. Update map with current sum.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count = 0;
        int sum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int x : nums) {

            // Convert to binary (odd = 1, even = 0)
            sum += (x % 2);

            // Check for valid subarrays
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Store current prefix sum
            mp[sum]++;
        }

        return count;
    }
};