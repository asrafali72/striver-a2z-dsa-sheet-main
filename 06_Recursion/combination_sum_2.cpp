/*
Problem: Combination Sum II

Platform: LeetCode

Short Explanation:
- Given a collection of candidate numbers (may contain duplicates) and a target,
  find all unique combinations where numbers sum to target.
- Each number can be used ONLY once.
- Sort the array to handle duplicates easily.
- Use backtracking:
    - Pick element and move to next index.
    - Skip duplicates using (j > i && can[j] == can[j-1]).
- Prune recursion when sum exceeds target.

Time Complexity: O(2^n * k)
Space Complexity: O(k)   // recursion stack
*/

class Solution {
public:

    void f(int i, int sum, vector<int>& can, int tar,
           vector<int> v, vector<vector<int>>& ans) {

        // Base case
        if (sum == tar) {
            ans.push_back(v);
            return;
        }

        // Stop conditions
        if (i == can.size() || sum > tar) return;

        for (int j = i; j < can.size(); j++) {

            // Skip duplicates
            if (j > i && can[j] == can[j - 1]) continue;

            // Choose element
            v.push_back(can[j]);

            // Move to next index (no reuse)
            f(j + 1, sum + can[j], can, tar, v, ans);

            // Backtrack
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& can, int tar) {
        sort(can.begin(), can.end());

        vector<vector<int>> ans;
        vector<int> v;

        f(0, 0, can, tar, v, ans);

        return ans;
    }
};