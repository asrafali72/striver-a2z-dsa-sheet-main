/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Next Greater Element II (Circular Array)

🧠 Intuition:
- Array is circular → after last element, we wrap to start.
- Trick: Traverse array twice using stack.
- Use monotonic decreasing stack to find next greater.

⚙️ Approach:
1. Push all elements into stack (simulate circular).
2. Traverse from right → left.
3. Pop smaller/equal elements.
4. If stack empty → -1 else top is answer.
5. Push current element back to stack.
6. Reverse result (since built backwards).

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> ans;
        stack<int> st;
        int n = nums.size();

        // Step 1: Push all elements (simulate circular)
        for (int i = n - 1; i >= 0; i--) {
            st.push(nums[i]);
        }

        // Step 2: Process elements
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // Store answer
            if (!st.empty()) ans.push_back(st.top());
            else ans.push_back(-1);

            // Push current element
            st.push(nums[i]);
        }

        // Reverse to correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};