/*
Problem: Count Good Numbers

Platform: LeetCode

Short Explanation:
- Even indices can have 5 choices (0,2,4,6,8).
- Odd indices can have 4 choices (2,3,5,7).
- Count = (5^even positions * 4^odd positions) % mod.
- Use fast exponentiation (binary power) for efficiency.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:

    long long mod = 1e9 + 7;

    // Fast exponentiation (Binary Exponentiation)
    long long power(long long x, long long n) {
        long long result = 1;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2; // positions with 5 choices
        long long odd = n / 2;        // positions with 4 choices

        long long ans = (power(5, even) * power(4, odd)) % mod;

        return (int)ans;
    }
};