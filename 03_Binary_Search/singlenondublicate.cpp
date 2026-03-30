/*
Problem: Single Element in a Sorted Array
Platform: LeetCode

Approach:
Use binary search. Pair indices (even, odd).
If pair is valid → move right, else move left.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            // Make mid even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1])
                lo = mid + 2;
            else
                hi = mid;
        }

        return nums[lo];
    }
};
