/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Sum of Subarray Minimums

🧠 Intuition:
- Each element contributes to multiple subarrays where it is the minimum.
- Count:
      Left = distance to Previous Smaller Element (PSE)
      Right = distance to Next Smaller Element (NSE)
- Contribution = arr[i] * left * right

⚙️ Approach:
1. Find Next Smaller Element (right boundary) using stack.
2. Find Previous Smaller Element (left boundary) using stack.
3. For each index:
      contribution = arr[i] * (i - PSE) * (NSE - i)
4. Take modulo (1e9 + 7).

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        // Next Smaller Element indices
        vector<int> next(n, n);
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] <= arr[st1.top()]) {
                st1.pop();
            }
            if (!st1.empty()) next[i] = st1.top();
            st1.push(i);
        }

        // Previous Smaller Element indices
        vector<int> prev(n, -1);
        stack<int> st2;

        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[i] < arr[st2.top()]) {
                st2.pop();
            }
            if (!st2.empty()) prev[i] = st2.top();
            st2.push(i);
        }

        // Calculate answer
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + (long long)arr[i] * left * right) % MOD;
        }

        return (int)ans;
    }
};