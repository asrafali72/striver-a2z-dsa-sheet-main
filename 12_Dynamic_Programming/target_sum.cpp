// File: target_sum.cpp

/*
Approach:
- Use Recursion + Memoization
- For every element:
    1. Add current number
    2. Subtract current number
- Store results using shifted index (sum + totalSum)
  to handle negative sums

Time Complexity: O(n * totalSum)
Space Complexity: O(n * totalSum)
*/

class Solution {
public:

    int solve(int i, int sum,
              vector<int>& nums,
              vector<vector<int>>& dp,
              int target,
              int total) {

        if (i == nums.size()) {

            return sum == target ? 1 : 0;
        }

        if (dp[i][sum + total] != INT_MIN)
            return dp[i][sum + total];

        int add =
            solve(i + 1,
                  sum + nums[i],
                  nums, dp,
                  target, total);

        int subtract =
            solve(i + 1,
                  sum - nums[i],
                  nums, dp,
                  target, total);

        return dp[i][sum + total] =
            add + subtract;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        int total = 0;

        for (int x : nums)
            total += x;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2 * total + 1,
                        INT_MIN)
        );

        return solve(0, 0,
                     nums, dp,
                     target, total);
    }
};