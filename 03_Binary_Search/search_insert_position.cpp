/*
Problem: Search Insert Position
Platform: LeetCode

Approach:
Use binary search to find the position of the target.
If the target exists, return its index.
Otherwise, return the index where it would be inserted
to maintain sorted order (i.e., first element >= target).

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int lo = 0, hi = nums.size() - 1;
        int ans = -1;

        if(nums[hi] < target)
            return hi + 1;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(target >= nums[mid]){
                if(target == nums[mid])
                    return mid;

                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans + 1;
    }
};
