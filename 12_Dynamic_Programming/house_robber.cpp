// File: house_robber.cpp

/*
Approach:
- Use Recursion + Memoization
- For every house:
    1. Rob current house and move to n-2
    2. Skip current house and move to n-1
- Store answers in dp array

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:

    int solve(int n, vector<int>& nums, vector<int>& dp) {

        if (n == 0)
            return nums[n];

        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + solve(n - 2, nums, dp);

        int notPick = solve(n - 1, nums, dp);

        return dp[n] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size() - 1;

        vector<int> dp(n + 2, -1);

        return solve(n, nums, dp);
    }
};