/*
Problem: Subsets

Platform: LeetCode

Short Explanation:
- Given an array of unique integers, return all possible subsets.
- Use recursion (pick / not-pick approach):
    - Pick the current element.
    - Do not pick the current element.
- When index reaches end, store the subset.

Time Complexity: O(2^n * n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
public:

    void f(int i, vector<int>& nums, vector<int> v, vector<vector<int>>& ans) {

        // Base case: reached end
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }

        // Pick current element
        v.push_back(nums[i]);
        f(i + 1, nums, v, ans);

        // Backtrack
        v.pop_back();

        // Not pick current element
        f(i + 1, nums, v, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;

        f(0, nums, v, ans);

        return ans;
    }
};