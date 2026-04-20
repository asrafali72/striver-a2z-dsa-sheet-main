/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Longest Repeating Character Replacement

🧠 Intuition:
- We want the longest substring where we can replace ≤ k chars
  to make all characters same.
- Key idea:
      window_size - max_frequency <= k
- Track max frequency of a single character in window.

⚙️ Approach:
1. Use sliding window.
2. Maintain frequency array of size 26.
3. Track max frequency in current window.
4. If replacements needed > k → shrink window.
5. Update answer.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int lo = 0;
        int ans = 0;
        int maxFreq = 0;

        for (int hi = 0; hi < s.size(); hi++) {

            // Update frequency
            freq[s[hi] - 'A']++;

            // Track max frequency in window
            maxFreq = max(maxFreq, freq[s[hi] - 'A']);

            // If replacements needed > k → shrink
            while ((hi - lo + 1) - maxFreq > k) {
                freq[s[lo] - 'A']--;
                lo++;
            }

            // Update answer
            ans = max(ans, hi - lo + 1);
        }

        return ans;
    }
};