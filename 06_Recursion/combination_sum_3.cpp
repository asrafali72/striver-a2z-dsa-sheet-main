/*
Problem: Combination Sum III

Platform: LeetCode

Short Explanation:
- Find all possible combinations of k numbers that add up to n.
- Only numbers from 1 to 9 can be used.
- Each number can be used at most once.
- Use recursion (pick / not-pick):
    - Pick current number and reduce k.
    - Skip current number.
- Start from 9 and go downwards.

Time Complexity: O(2^9 * k)
Space Complexity: O(k)   // recursion stack
*/

class Solution {
public:

    void f(int n, int k, int sum, int num,
           vector<int> v, vector<vector<int>>& ans) {

        // If k numbers selected
        if (k == 0) {
            if (sum == n) ans.push_back(v);
            return;
        }

        // No numbers left
        if (num == 0) return;

        // Pick current number
        v.push_back(num);
        f(n, k - 1, sum + num, num - 1, v, ans);

        // Backtrack
        v.pop_back();

        // Not pick current number
        f(n, k, sum, num - 1, v, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;

        f(n, k, 0, 9, v, ans);

        return ans;
    }
};