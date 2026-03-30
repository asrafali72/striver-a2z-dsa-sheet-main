/*
Problem: Missing Number
Platform: LeetCode

Approach:
The array contains numbers from 0 to n with exactly one number missing.
First compute the expected sum of numbers from 0 to n using the formula
n*(n+1)/2. Then subtract every element of the array from this total.
The remaining value will be the missing number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int total = n * (n + 1) / 2;

        for(int i = 0; i < nums.size(); i++){
            total -= nums[i];
        }

        return total;
    }
};
