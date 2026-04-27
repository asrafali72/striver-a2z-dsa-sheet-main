/*
===========================================================
📌 Problem: Top K Frequent Elements (LeetCode 347)

🧠 Intuition:
- We need k elements with highest frequency.
- Instead of sorting whole array:
      use Max Heap to always get highest frequency element.

⚙️ Approach:
1. Count frequency using hashmap.
2. Push (frequency, element) into Max Heap.
3. Extract top k elements from heap.

⏱️ Time Complexity: O(N log N)
📦 Space Complexity: O(N)

💡 Optimization:
- Can be improved to O(N log K) using Min Heap of size k.

===========================================================
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Max Heap (frequency, element)
        priority_queue<pair<int, int>> pq;
        for (auto [num, count] : freq) {
            pq.push({count, num});
        }

        vector<int> ans;

        // Step 3: Get top k elements
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};