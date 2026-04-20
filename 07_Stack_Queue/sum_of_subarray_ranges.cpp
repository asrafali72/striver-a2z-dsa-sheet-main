/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Sum of Subarray Ranges

🧠 Intuition:
- Range = max - min for every subarray.
- Instead of generating all subarrays:
      👉 Compute contribution of each element as:
         • Minimum (using monotonic increasing stack)
         • Maximum (using monotonic decreasing stack)
- Final Answer = sum(max contributions) - sum(min contributions)

⚙️ Approach:
1. Create function f() → sum of subarray minimums.
2. Create function f1() → sum of subarray maximums.
3. Use Previous Smaller/Greater and Next Smaller/Greater indices.
4. Contribution:
      arr[i] * (i - prev) * (next - i)

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:

    // Sum of subarray minimums
    long long f(vector<int>& arr) {

        int n = arr.size();
        vector<int> next(n, n), prev(n, -1);
        stack<int> st1, st2;

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] <= arr[st1.top()]) {
                st1.pop();
            }
            if (!st1.empty()) next[i] = st1.top();
            st1.push(i);
        }

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[i] < arr[st2.top()]) {
                st2.pop();
            }
            if (!st2.empty()) prev[i] = st2.top();
            st2.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans += (long long)arr[i] * left * right;
        }

        return ans;
    }

    // Sum of subarray maximums
    long long f1(vector<int>& arr) {

        int n = arr.size();
        vector<int> next(n, n), prev(n, -1);
        stack<int> st1, st2;

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[i] > arr[st1.top()]) {
                st1.pop();
            }
            if (!st1.empty()) next[i] = st1.top();
            st1.push(i);
        }

        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[i] >= arr[st2.top()]) {
                st2.pop();
            }
            if (!st2.empty()) prev[i] = st2.top();
            st2.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans += (long long)arr[i] * left * right;
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini = f(nums);
        long long maxi = f1(nums);
        return maxi - mini;
    }
};