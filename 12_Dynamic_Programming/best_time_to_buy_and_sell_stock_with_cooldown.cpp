// File: best_time_to_buy_and_sell_stock_with_cooldown.cpp

/*
Approach:
- Use Recursion + Memoization
- Two states:
    1. Buy allowed
    2. Sell allowed
- After selling, move to i+2 due to cooldown
- Store results in dp array

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:

    int solve(int i, int buy,
              vector<int>& prices,
              vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        // Buy allowed
        if (buy) {

            int take =
                -prices[i] +
                solve(i + 1, 0,
                      prices, dp);

            int skip =
                solve(i + 1, 1,
                      prices, dp);

            profit = max(take, skip);
        }

        // Sell allowed
        else {

            int sell =
                prices[i] +
                solve(i + 2, 1,
                      prices, dp);

            int skip =
                solve(i + 1, 0,
                      prices, dp);

            profit = max(sell, skip);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(0, 1,
                     prices, dp);
    }
};