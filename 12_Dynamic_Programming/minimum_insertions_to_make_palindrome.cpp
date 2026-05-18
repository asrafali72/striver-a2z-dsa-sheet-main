// File: minimum_insertions_to_make_palindrome.cpp

/*
Approach:
- Use Recursion + Memoization
- If characters match:
    move inward
- Otherwise:
    insert character at either side
    and take minimum operations

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

class Solution {
public:

    int solve(string& s,
              int i, int j,
              vector<vector<int>>& dp) {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j]) {

            return dp[i][j] =
                solve(s,
                      i + 1,
                      j - 1,
                      dp);
        }

        return dp[i][j] =
            1 + min(
                    solve(s,
                          i + 1,
                          j,
                          dp),

                    solve(s,
                          i,
                          j - 1,
                          dp)
                );
    }

    int minInsertions(string s) {

        vector<vector<int>> dp(
            s.size() + 1,
            vector<int>(s.size() + 1, -1)
        );

        return solve(s,
                     0,
                     s.size() - 1,
                     dp);
    }
};