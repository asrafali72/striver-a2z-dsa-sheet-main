/*
Problem: Combination Sum

Platform: LeetCode

Short Explanation:
- Given an array of distinct integers and a target,
  find all unique combinations where elements sum to target.
- Each element can be used unlimited times.
- At each step:
    - Include current element (stay at same index).
    - Exclude current element (move to next index).
- Use recursion (backtracking) to explore all possibilities.

Time Complexity: O(2^n * k)   // k = avg length of combination
Space Complexity: O(k)        // recursion stack
*/

class Solution {
public:

    void f(int i, int sum, vector<int>& can, int tar,
           vector<vector<int>>& ans, vector<int> v) {

        // Base case: target achieved
        if (sum == tar) {
            ans.push_back(v);
            return;
        }

        // Out of bounds or exceeded target
        if (i == can.size() || sum > tar) return;

        // Include current element (reuse allowed)
        v.push_back(can[i]);
        f(i, sum + can[i], can, tar, ans, v);
        v.pop_back();

        // Exclude current element (move to next)
        f(i + 1, sum, can, tar, ans, v);
    }

    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>> ans;
        vector<int> v;

        f(0, 0, can, tar, ans, v);

        return ans;
    }
};