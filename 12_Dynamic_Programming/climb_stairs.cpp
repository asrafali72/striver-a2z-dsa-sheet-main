// File: climb_stairs.cpp

/*
Approach:
- Use Recursion + Memoization
- Store answers in dp array to avoid recalculation

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    
    int solve(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] =
            solve(n - 1, dp) +
            solve(n - 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};