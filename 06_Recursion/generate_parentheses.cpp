/*
Problem: Generate Parentheses

Platform: LeetCode

Short Explanation:
- We generate all valid combinations of n pairs of parentheses.
- At any step:
    - We can add '(' if we still have opening brackets left.
    - We can add ')' only if closing brackets are less than opening (to maintain validity).
- Use recursion (backtracking) to build all valid strings.

Time Complexity: O(2^n * n)
Space Complexity: O(n)  // recursion stack
*/

class Solution {
public:

    void f(int open, int close, string s, vector<string>& ans) {

        // Base case
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open > 0) {
            f(open - 1, close, s + '(', ans);
        }

        // Add closing bracket (only if valid)
        if (open < close) {
            f(open, close - 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, n, "", ans);
        return ans;
    }
};