/*
Problem: Binary Search
Platform: LeetCode

Approach:
Use binary search on the sorted array.
Compare the middle element with the target.
If equal, return index. If smaller, search right half.
If greater, search left half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int lo = 0, hi = nums.size() - 1;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return -1;
    }
};
