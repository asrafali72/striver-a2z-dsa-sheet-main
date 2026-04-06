/*
Problem: Pow(x, n)

Platform: LeetCode

Short Explanation:
- Multiply x repeatedly for positive n.
- For negative n, divide instead.
- Handle negative power using absolute value.
- Return final computed result.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {

        double ans = x;

        // Positive power
        if (0 < n) {
            for (int i = 1; i < n; i++) {
                ans *= x;
            }
        }
        // Negative power
        else {
            long n1 = n;
            for (int i = 0; i <= abs(n1); i++) {
                ans /= x;
            }
        }

        return ans;
    }
};