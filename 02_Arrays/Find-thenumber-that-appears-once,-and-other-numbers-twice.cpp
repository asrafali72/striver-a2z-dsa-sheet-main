/*
Problem: Single Number
Platform: LeetCode

Approach:
Use the XOR property. When two identical numbers are XORed, the result is 0,
and when a number is XORed with 0, the result is the number itself.
Since every element appears twice except one, XORing all elements
will cancel the duplicates and leave the single number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

