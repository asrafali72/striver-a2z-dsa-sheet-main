/*
Problem: Find Rotation Count in Rotated Sorted Array
Platform: GeeksforGeeks

Approach:
The index of the minimum element gives the number of rotations.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKRotation(vector<int> &nums) {

        int lo = 0, hi = nums.size() - 1;

        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        return lo;
    }
};
