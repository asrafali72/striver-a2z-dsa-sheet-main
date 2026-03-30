/*
Problem: Sum of First N Natural Numbers
Platform: GeeksforGeeks

Approach:
Use recursion. Add the current number n with the sum of
numbers from (n-1) until n becomes 0.

Time Complexity: O(n)
Space Complexity: O(n) (recursion stack)
*/

int nSum(int n) {

    if(n == 0)
        return n;

    return n + nSum(n - 1);
}
