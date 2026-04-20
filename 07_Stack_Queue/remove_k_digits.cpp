/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Remove K Digits

🧠 Intuition:
- To get the smallest number:
      👉 Remove digits that are larger than the next digit.
- Use a monotonic increasing stack:
      - Maintain smallest possible number greedily.

⚙️ Approach:
1. Traverse digits:
      - While current digit < stack top AND k > 0 → pop
2. Push current digit.
3. If k still remains → remove from end.
4. Remove leading zeros.
5. If empty → return "0".

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    string removeKdigits(string num, int k) {

        // Edge case
        if (num.size() == k) return "0";

        stack<char> st;

        // Step 1: Build monotonic increasing stack
        for (char ch : num) {

            while (!st.empty() && ch < st.top() && k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // Step 2: Build string from stack
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Step 3: Remove remaining k digits from end
        while (k > 0) {
            ans.pop_back();
            k--;
        }

        // Step 4: Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i);

        // Step 5: Edge case
        return ans.empty() ? "0" : ans;
    }
};