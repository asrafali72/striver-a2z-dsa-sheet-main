/*
Problem: Reverse Integer
Platform: LeetCode

Approach:
Extract digits using modulo (%) and build the reversed number
by multiplying the result by 10 and adding the digit.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        int a = 0;
        while(x){
            a = a * 10 + (x % 10);
            x = x / 10;
        }
        return a;
    }
};
