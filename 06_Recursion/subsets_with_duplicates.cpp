/*
Problem: Subsets II

Platform: LeetCode

Short Explanation:
- Given an integer array that may contain duplicates,
  return all possible subsets (the power set) without duplicates.
- Sort the array to group duplicates together.
- Use backtracking:
    - At every step, add current subset to answer.
    - Iterate through elements and pick each one.
    - Skip duplicates using (j > i && nums[j] == nums[j-1]).

Time Complexity: O(2^n * n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
public:

    void f(int i, vector<int>& nums, vector<int> v, vector<vector<int>>& ans) {

        // Add current subset
        ans.push_back(v);

        for (int j = i; j < nums.size(); j++) {

            // Skip duplicates
            if (j > i && nums[j] == nums[j - 1]) continue;

            // Choose element
            v.push_back(nums[j]);

            // Move to next index
            f(j + 1, nums, v, ans);

            // Backtrack
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        f(0, nums, v, ans);

        return ans;
    }
};