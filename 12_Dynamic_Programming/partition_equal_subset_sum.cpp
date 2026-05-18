// File: partition_equal_subset_sum.cpp

/*
Approach:
- Find total sum of array
- If sum is odd, partition is not possible
- Use Recursion + Memoization
- Try both choices:
    1. Pick current element
    2. Skip current element
- Check if subset with sum/2 exists

Time Complexity: O(n * sum)
Space Complexity: O(n * sum)
*/

class Solution {
public:

    bool solve(int i, int s,
               vector<int>& nums,
               int target,
               vector<vector<int>>& dp) {

        if (s == target)
            return true;

        if (i == nums.size() || s > target)
            return false;

        if (dp[i][s] != -1)
            return dp[i][s];

        bool notPick =
            solve(i + 1, s,
                  nums, target, dp);

        bool pick =
            solve(i + 1,
                  s + nums[i],
                  nums, target, dp);

        return dp[i][s] =
            pick || notPick;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        sum /= 2;

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, -1)
        );

        return solve(0, 0,
                     nums, sum, dp);
    }
};