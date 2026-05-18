// File: edit_distance.cpp

/*
Approach:
- Use Recursion + Memoization
- If characters match:
    move to next characters
- Otherwise perform:
    1. Replace
    2. Delete
    3. Insert
- Take minimum operations

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

class Solution {
public:

    int solve(int i, int j,
              string& word1,
              string& word2,
              vector<vector<int>>& dp) {

        if (j == word2.size())
            return word1.size() - i;

        if (i == word1.size())
            return word2.size() - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {

            return dp[i][j] =
                solve(i + 1,
                      j + 1,
                      word1, word2,
                      dp);
        }

        int replace =
            solve(i + 1,
                  j + 1,
                  word1, word2,
                  dp);

        int del =
            solve(i + 1,
                  j,
                  word1, word2,
                  dp);

        int insert =
            solve(i,
                  j + 1,
                  word1, word2,
                  dp);

        return dp[i][j] =
            1 + min({replace,
                     del,
                     insert});
    }

    int minDistance(string word1,
                    string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(0, 0,
                     word1, word2,
                     dp);
    }
};