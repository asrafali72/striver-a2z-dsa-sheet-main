/*
Problem: Count Occurrences in Sorted Array
Platform: GeeksforGeeks

Approach:
Use binary search twice:
1. Find the last occurrence of x.
2. Find the first occurrence of x.
If x is not found, return 0.
Otherwise, frequency = (last index - first index + 1).

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int countFreq(vector<int>& arr, int x) {

        int ans = -1;
        int lo = 0, hi = arr.size() - 1;

        // Find last occurrence
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(arr[mid] == x){
                ans = mid;
                lo = mid + 1;
            }
            else if(arr[mid] < x){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        int ans1 = -1;
        lo = 0;
        hi = arr.size() - 1;

        // Find first occurrence
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(arr[mid] == x){
                ans1 = mid;
                hi = mid - 1;
            }
            else if(arr[mid] > x){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        if(ans == -1 && ans1 == -1)
            return 0;

        return ans - ans1 + 1;
    }
};
