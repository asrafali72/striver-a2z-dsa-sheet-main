/*
Problem: Fibonacci Number
Platform: LeetCode

Approach:
Use recursion with parameters representing the previous two Fibonacci
numbers. Update them at each recursive call until n becomes 0 or 1.

Time Complexity: O(n)
Space Complexity: O(n) (recursion stack)
*/

class Solution {
public:

    int f(int a, int b, int n){
        if(n == 0) return a;
        if(n == 1) return b;

        return f(b, a + b, n - 1);
    }

    int fib(int n) {
        return f(0, 1, n);
    }
};
