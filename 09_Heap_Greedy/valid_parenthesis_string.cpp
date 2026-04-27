/*
===========================================================
📌 Problem: Valid Parenthesis String (LeetCode 678)

🧠 Intuition:
- '*' can act as '(', ')' or empty.
- Instead of trying all possibilities:
      track a range of possible open brackets.

- lo → minimum possible open '('
- hi → maximum possible open '('

⚙️ Approach:
1. Traverse string:
      - If '(' → lo++, hi++
      - If ')' → lo--, hi--
      - If '*' → lo--, hi++   (flexible)
2. If hi < 0 → too many ')' → invalid
3. If lo < 0 → reset to 0 (cannot go negative)
4. At end:
      lo == 0 → valid string

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    bool checkValidString(string s) {

        int lo = 0, hi = 0;

        for (char c : s) {

            if (c == '(') {
                lo++;
                hi++;
            }
            else if (c == ')') {
                lo--;
                hi--;
            }
            else { // '*'
                lo--;
                hi++;
            }

            // Too many closing brackets
            if (hi < 0) return false;

            // lo cannot be negative
            if (lo < 0) lo = 0;
        }

        return lo == 0;
    }
};