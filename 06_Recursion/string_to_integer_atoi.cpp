/*
Problem: String to Integer (atoi)

Platform: LeetCode

Short Explanation:
- Ignore leading spaces.
- Check sign (+ / -).
- Convert digits into number.
- Stop at first non-digit character.
- Handle overflow using INT limits.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:

    void f(string s, int i, long long &ans, int &c) {

        if (i == s.size()) return;

        if (s[i] == ' ' && c == 0) {
            f(s, i + 1, ans, c);
        }
        else if (s[i] == '+' && c == 0) {
            c = 1;
            f(s, i + 1, ans, c);
        }
        else if (s[i] == '-' && c == 0) {
            c = -1;
            f(s, i + 1, ans, c);
        }
        else if (isdigit(s[i])) {
            if (c == 0) c = 1;

            ans = ans * 10 + (s[i] - '0');

            if (INT_MAX <= ans) return; // overflow check

            f(s, i + 1, ans, c);
        }
        else return;
    }

    int myAtoi(string s) {

        long long ans = 0;
        int c = 0; // sign

        f(s, 0, ans, c);

        if (c == -1) ans *= -1;

        if (ans <= INT_MIN) return INT_MIN;
        if (INT_MAX <= ans) return INT_MAX;

        return ans;
    }
};