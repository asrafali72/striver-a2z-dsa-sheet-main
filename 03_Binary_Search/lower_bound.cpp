/*
Problem: Lower Bound
Platform: GeeksforGeeks

Approach:
Use binary search to find the first index where element is
greater than or equal to target. If such an element is found,
store the index and continue searching in the left half to
find the smallest possible index.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {

        int ans = -1;
        int lo = 0, hi = arr.size() - 1;

        if(arr[hi] < target)
            return hi + 1;

        while(lo <= hi){

            int mid = lo + (hi - lo) / 2;

            if(target <= arr[mid]){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};
