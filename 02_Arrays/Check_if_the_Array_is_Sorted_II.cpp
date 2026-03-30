/*
Problem: Check if Array is Sorted and Rotated

Platform: LeetCode

Problem Statement:
Given an array nums, return true if the array was originally sorted in
non-decreasing order and then rotated some number of times (possibly zero).
Otherwise, return false.

An array A rotated by x positions results in an array B of the same length
such that:
B[i] = A[(i + x) % A.length]

Example 1:
Input: nums = [3,4,5,1,2]
Output: true

Example 2:
Input: nums = [2,1,3,4]
Output: false

Approach:
A sorted and rotated array will have at most one "drop" point where
nums[i] > nums[i+1].

Steps:
1. Traverse the array and count the number of positions where
   nums[i] > nums[i+1].
2. Also check the last element with the first element because
   rotation connects them.
3. If the number of drops is greater than 1, the array cannot be
   sorted and rotated.
4. If the number of drops is 0 or 1, return true.

Time Complexity: O(n)
We traverse the array once.

Space Complexity: O(1)
No extra space is used.
*/

class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;

        if(nums[0] < nums[nums.size()-1])
            count++;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1])
                count++;
        }

        return count <= 1;
    }
};
