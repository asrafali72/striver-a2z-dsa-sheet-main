/*
Problem: Find Minimum in Rotated Sorted Array
Platform: LeetCode

Approach:
Use binary search. Compare mid with hi.
If nums[mid] > nums[hi], minimum is in right half,
otherwise in left half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int lo = 0, hi = nums.size() - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        return nums[lo];
    }
};
