/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Next Greater Element I

🧠 Intuition:
- Use a monotonic decreasing stack to efficiently find
  the next greater element for each number in nums2.
- Store results in a hashmap for O(1) lookup.

⚙️ Approach:
1. Traverse nums2 from right → left.
2. Pop all smaller/equal elements from stack.
3. If stack empty → -1 else top is answer.
4. Store result in map.
5. Build answer for nums1 using map.

⏱️ Time Complexity: O(n + m)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp; // value → next greater
        stack<int> st;              // monotonic stack

        // Process nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {

            int num = nums2[i];

            // Remove smaller elements
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // Store result
            mp[num] = st.empty() ? -1 : st.top();

            // Push current element
            st.push(num);
        }

        // Build result for nums1
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};