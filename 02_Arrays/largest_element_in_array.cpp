/*
Problem: Largest Element in Array

Platform: GeeksforGeeks

Problem Statement:
Given an array of integers, find the largest element in the array.

Example:
Input: arr = [1, 8, 7, 56, 90]
Output: 90

Approach:
- Initialize a variable `la` with the first element of the array.
- Traverse the array from index 1 to n-1.
- If the current element is greater than `la`, update `la`.
- After traversing the array, `la` will contain the largest element.

Time Complexity: O(n)
We traverse the array once.

Space Complexity: O(1)
No extra space is used.

*/

class Solution {
public:
    int largest(vector<int> &arr) {
        int la = arr[0];

        for(int i = 1; i < arr.size(); i++){
            if(la < arr[i])
                la = arr[i];
        }

        return la;
    }
};
