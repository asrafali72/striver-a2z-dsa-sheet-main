/*
Problem: GCD of Two Numbers
Platform: GeeksforGeeks

Approach:
Use Euclid's Algorithm. Repeatedly replace (a, b) with (b, a % b)
until b becomes 0. The remaining value of a is the GCD.

Time Complexity: O(log(min(a,b)))
Space Complexity: O(log(min(a,b))) (due to recursion)
*/

class Solution {
public:
    int gcd(int a, int b) {

        if(b == 0)
            return a;

        return gcd(b, a % b);
    }
};
