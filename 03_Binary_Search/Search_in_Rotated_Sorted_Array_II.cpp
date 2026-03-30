/*
Problem: Search in Rotated Sorted Array II
Platform: LeetCode

Approach:
Same as rotated search, but handle duplicates by shrinking
boundaries when nums[lo] == nums[mid] == nums[hi].

Time Complexity: O(n) worst case
Space Complexity: O(1)
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target) return true;

            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++; hi--;
            }
            else if(nums[lo] <= nums[mid]){
                if(nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }

        return false;
    }
};
