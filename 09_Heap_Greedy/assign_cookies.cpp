/*
===========================================================
📌 Problem: Assign Cookies (LeetCode 455)

🧠 Intuition:
- Each child has a greed factor, each cookie has a size.
- A child is satisfied if cookie size ≥ greed.
- Goal: maximize number of satisfied children.
- Greedy idea:
      Always try to satisfy the least greedy child first.

⚙️ Approach:
1. Sort greed array (g) and cookie array (s).
2. Use two pointers:
      i → children
      j → cookies
3. If s[j] ≥ g[i]:
      - Assign cookie → move both pointers
   Else:
      - Try next bigger cookie (j++)
4. Return number of satisfied children (i)

⏱️ Time Complexity: O(N log N + M log M)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;

        while (i < g.size() && j < s.size()) {

            if (s[j] >= g[i]) {
                i++;  // child satisfied
            }

            j++;  // move to next cookie
        }

        return i;
    }
};