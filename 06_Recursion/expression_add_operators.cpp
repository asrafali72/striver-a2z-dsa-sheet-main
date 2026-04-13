/*
Problem: Expression Add Operators

Platform: LeetCode

Short Explanation:
- Given a string of digits and a target, insert '+', '-', '*'
  between digits to form valid expressions that evaluate to target.
- Use backtracking:
    - Try all possible partitions of the string.
    - At each step, try adding '+', '-', '*'.
- Key trick:
    - Handle multiplication using previous value (prev)
      to maintain correct precedence.

Time Complexity: O(4^n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
public:

    void solve(int index, string& num, int target,
               long long sum, long long prev,
               string expr, vector<string>& ans) {

        // Base case
        if (index == num.size()) {
            if (sum == target) {
                ans.push_back(expr);
            }
            return;
        }

        // Try all partitions
        for (int i = index; i < num.size(); i++) {

            // Skip leading zeros
            if (i > index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);

            // First number (no operator)
            if (index == 0) {
                solve(i + 1, num, target, val, val, part, ans);
            }
            else {
                // Addition
                solve(i + 1, num, target,
                      sum + val, val,
                      expr + "+" + part, ans);

                // Subtraction
                solve(i + 1, num, target,
                      sum - val, -val,
                      expr + "-" + part, ans);

                // Multiplication (handle precedence)
                solve(i + 1, num, target,
                      sum - prev + (prev * val),
                      prev * val,
                      expr + "*" + part, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, num, target, 0, 0, "", ans);

        return ans;
    }
};