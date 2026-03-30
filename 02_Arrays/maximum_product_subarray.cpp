/*
Problem: Maximum Product Subarray
Platform: LeetCode

Approach:
Traverse the array twice (left to right and right to left).
Keep multiplying elements and track the maximum product.
If the product becomes 0, reset it to 1.
This handles negative numbers and zero cases properly.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int mul = 1, maxi = INT_MIN;

        for(int i : nums){
            mul *= i;
            maxi = max(maxi, mul);

            if(mul == 0)
                mul = 1;
        }

        mul = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            mul *= nums[i];
            maxi = max(maxi, mul);

            if(mul == 0)
                mul = 1;
        }

        return maxi;
    }
};
