/*
Problem: String to Integer (atoi)

Platform: LeetCode

Short Explanation:
- Skip leading spaces.
- Check sign (+ / -).
- Convert digits into number.
- Handle overflow using long long.
- Clamp result within INT range.

Time Complexity: O(n)
Space Complexity: O(n)  // recursion stack
*/

class Solution {
public:
    void f(string s, int i, long long &ans, int &c){
        if(i == s.size()) return;

        if(s[i] == ' ' && c == 0){
            f(s, i + 1, ans, c);
        }
        else if(s[i] == '+' && c == 0){
            c = 1;
            f(s, i + 1, ans, c);
        }
        else if(s[i] == '-' && c == 0){
            c = -1;
            f(s, i + 1, ans, c);
        }
        else if(isdigit(s[i])){
            if(c == 0) c = 1;

            ans = ans * 10 + (s[i] - '0');

            if(ans >= INT_MAX) return;

            f(s, i + 1, ans, c);
        }
        else return;
    }

    int myAtoi(string s) {

        long long ans = 0;
        int c = 0;

        f(s, 0, ans, c);

        if(c == -1) ans *= -1;

        if(ans <= INT_MIN) return INT_MIN;
        if(ans >= INT_MAX) return INT_MAX;

        return ans;
    }
};