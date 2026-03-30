/*
Problem: Palindrome Number
Platform: LeetCode

Approach:
Reverse the digits of the number and compare it with the original number.
If both are equal, the number is a palindrome.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {

        long long ans = 0;
        long long ans1 = x;

        while(0 < x){
            long long i = x % 10;
            ans = (ans * 10) + i;
            x = x / 10;
        }

        if(ans == ans1)
            return true;

        return false;
    }
};
