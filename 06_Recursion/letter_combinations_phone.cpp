/*
Problem: Letter Combinations of a Phone Number

Platform: LeetCode

Short Explanation:
- Given a string of digits (2–9), return all possible letter combinations.
- Each digit maps to letters like a phone keypad.
- Use backtracking:
    - For each digit, try all possible mapped characters.
    - Build the string step by step.
- When index reaches end → store the combination.

Time Complexity: O(4^n * n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
public:

    void f(vector<string>& m, vector<string>& ans,
           string& s, string& digi, int index) {

        // Base case
        if (index == digi.length()) {
            ans.push_back(s);
            return;
        }

        int digit = digi[index] - '0';
        string value = m[digit];

        for (int i = 0; i < value.length(); i++) {

            // Choose character
            s.push_back(value[i]);

            // Recurse for next digit
            f(m, ans, s, digi, index + 1);

            // Backtrack
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digi) {

        // Mapping
        vector<string> m(10);
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";

        vector<string> ans;

        // Edge case
        if (digi.size() == 0) return ans;

        string s = "";

        f(m, ans, s, digi, 0);

        return ans;
    }
};