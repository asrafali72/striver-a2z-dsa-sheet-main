/*
Problem: Count Digits

Platform: GeeksforGeeks / Basic DSA Problem

Problem Statement:
Given an integer n, count the total number of digits present in the number.

Example 1:
Input: n = 12345
Output: 5

Example 2:
Input: n = 7
Output: 1

Approach:
The idea is to repeatedly divide the number by 10 until it becomes 0.

Steps:
1. Initialize a counter variable count = 0.
2. While n is not equal to 0:
   - Increase count by 1.
   - Divide n by 10 to remove the last digit.
3. When n becomes 0, return the value of count.

Time Complexity: O(log10 n)
Each division removes one digit.

Space Complexity: O(1)
No extra space is used.
*/

class Solution {
public:
    int countDigits(int n) {

        int count = 0;

        while(n){
            count++;
            n /= 10;
        }

        return count;
    }
};
