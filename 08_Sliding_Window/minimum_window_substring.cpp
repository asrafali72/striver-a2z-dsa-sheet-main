/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Minimum Window Substring

🧠 Intuition:
- Find the smallest substring in s that contains all chars of t.
- Use sliding window + frequency map:
      • Expand (hi) → include characters
      • Shrink (lo) → minimize window when valid

⚙️ Approach:
1. Store frequency of characters in t.
2. Maintain a counter `required` = number of chars needed.
3. Expand window:
      - Decrease freq
      - If valid char → reduce required
4. When required == 0:
      - Try shrinking window
      - Update minimum length
5. Return smallest substring.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1) (fixed charset)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        unordered_map<char, int> freq;

        // Step 1: Build frequency map
        for (char ch : t) freq[ch]++;

        int lo = 0;
        int start = -1;
        int minLen = INT_MAX;

        int required = t.size();

        for (int hi = 0; hi < s.size(); hi++) {

            // Include current character
            freq[s[hi]]--;

            if (freq[s[hi]] >= 0) {
                required--;
            }

            // Shrink window when valid
            while (required == 0) {

                if (hi - lo + 1 < minLen) {
                    minLen = hi - lo + 1;
                    start = lo;
                }

                freq[s[lo]]++;

                if (freq[s[lo]] > 0) {
                    required++;
                }

                lo++;
            }
        }

        return (start == -1) ? "" : s.substr(start, minLen);
    }
};