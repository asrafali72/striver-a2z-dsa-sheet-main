/*
Problem: Allocate Minimum Number of Pages
Platform: GFG

Approach:
Binary Search on maximum pages.
Check if books can be allocated within k students.

Time Complexity: O(n * log(sum(arr)))
Space Complexity: O(1)
*/

class Solution {
public:

    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int count = 1;
        int pages = 0;

        for (int i : arr) {
            if (i > maxPages) return false;

            if (pages + i <= maxPages) {
                pages += i;
            } else {
                count++;
                pages = i;
            }
        }

        return count <= k;
    }

    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;

        int lo = 0, hi = 0, ans = -1;

        for (int i : arr)
            hi += i;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
