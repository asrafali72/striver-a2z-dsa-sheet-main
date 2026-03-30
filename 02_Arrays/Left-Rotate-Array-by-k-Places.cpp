/*
Problem: Rotate Array

Platform: LeetCode

Problem Statement:
Given an integer array nums, rotate the array to the right by k steps,
where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Approach:
We use the Reversal Algorithm.

Steps:
1. Compute k = k % n (to handle cases where k > n).
2. Reverse the entire array.
3. Reverse the first k elements.
4. Reverse the remaining n-k elements.

This results in the array being rotated k steps to the right.

Example:
nums = [1,2,3,4,5,6,7], k = 3

Step 1: Reverse whole array
[7,6,5,4,3,2,1]

Step 2: Reverse first k elements
[5,6,7,4,3,2,1]

Step 3: Reverse remaining elements
[5,6,7,1,2,3,4]

Time Complexity: O(n)
Each reverse operation takes linear time.

Space Complexity: O(1)
The rotation is done in-place without extra memory.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
