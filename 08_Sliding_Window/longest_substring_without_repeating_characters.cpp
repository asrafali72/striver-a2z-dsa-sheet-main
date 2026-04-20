/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Longest Substring Without Repeating Characters

🧠 Intuition:
- Use sliding window to maintain a substring with unique characters.
- Expand window using `hi`, shrink using `lo` when duplicate appears.

⚙️ Approach:
1. Use unordered_set to track characters in current window.
2. Move `hi` forward:
      - If duplicate found → shrink window from `lo`
3. Update max length at each step.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st; // store unique characters

        int lo = 0, hi = 0;
        int ans = 0;

        while (hi < s.size()) {

            // Remove duplicates
            while (lo <= hi && st.find(s[hi]) != st.end()) {
                st.erase(s[lo]);
                lo++;
            }

            // Add current character
            st.insert(s[hi]);

            // Update answer
            ans = max(ans, hi - lo + 1);

            hi++;
        }

        return ans;
    }
};