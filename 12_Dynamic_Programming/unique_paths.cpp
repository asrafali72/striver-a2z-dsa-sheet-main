// File: unique_paths.cpp

/*
Approach:
- Use Space Optimized DP
- First row is initialized with 1
- Each cell can be reached from:
    1. Top cell
    2. Left cell
- dp[j] = dp[j] + dp[j-1]

Time Complexity: O(m * n)
Space Complexity: O(n)
*/

class Solution {
public:

    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};