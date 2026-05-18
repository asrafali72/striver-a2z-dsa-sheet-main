// File: coin_change_ii.cpp

/*
Approach:
- Use Recursion + Memoization
- For every coin:
    1. Take current coin (stay at same index)
    2. Skip current coin
- Count total number of ways to make amount

Time Complexity: O(n * amount)
Space Complexity: O(n * amount)
*/

class Solution {
public:

    int solve(int n, int amount,
              vector<int>& coins,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 1;

        if (n == 0)
            return 0;

        if (dp[n][amount] != -1)
            return dp[n][amount];

        if (coins[n - 1] <= amount) {

            return dp[n][amount] =
                solve(n,
                      amount - coins[n - 1],
                      coins, dp)

                +

                solve(n - 1,
                      amount,
                      coins, dp);
        }

        return dp[n][amount] =
            solve(n - 1,
                  amount,
                  coins, dp);
    }

    int change(int amount,
               vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        return solve(n, amount,
                     coins, dp);
    }
};