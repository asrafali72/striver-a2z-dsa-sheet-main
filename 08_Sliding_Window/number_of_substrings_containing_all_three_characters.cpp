/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Number of Substrings Containing All Three Characters

🧠 Intuition:
- We need substrings containing at least one 'a', 'b', and 'c'.
- Use sliding window:
      • Expand window (hi)
      • When valid (a>0, b>0, c>0):
            → All substrings from hi to end are valid

⚙️ Approach:
1. Maintain counts of 'a', 'b', 'c'.
2. Expand hi pointer.
3. When all counts > 0:
      - Add (n - hi) to answer
      - Shrink window from lo
4. Continue until end.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int numberOfSubstrings(string s) {

        int a = 0, b = 0, c = 0;
        int ans = 0;

        int lo = 0;

        for (int hi = 0; hi < s.size(); hi++) {

            // Update counts
            if (s[hi] == 'a') a++;
            else if (s[hi] == 'b') b++;
            else c++;

            // Shrink window when valid
            while (a > 0 && b > 0 && c > 0) {

                ans += (s.size() - hi);

                if (s[lo] == 'a') a--;
                else if (s[lo] == 'b') b--;
                else c--;

                lo++;
            }
        }

        return ans;
    }
};