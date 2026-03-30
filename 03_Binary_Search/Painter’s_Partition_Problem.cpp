/*
Problem: Painter’s Partition Problem
Platform: GFG

Approach:
Binary Search on maximum time.
Check if boards can be painted within k painters.

Time Complexity: O(n * log(sum(arr)))
Space Complexity: O(1)
*/

class Solution {
public:

    bool isPossible(vector<int> arr, int maxTime, int k) {
        int count = 1, currTime = 0;

        for (int i : arr) {
            if (i > maxTime) return false;

            if (currTime + i <= maxTime) {
                currTime += i;
            } else {
                count++;
                currTime = i;
            }
        }

        return count <= k;
    }

    int minTime(vector<int>& arr, int k) {
        if (arr.size() < k) return -1;

        int lo = 0, hi = 0, ans = 0;

        for (int i : arr)
            hi += i;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isPossible(arr, mid, k)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
