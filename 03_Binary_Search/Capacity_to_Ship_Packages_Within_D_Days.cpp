/*
Problem: Capacity to Ship Packages Within D Days
Platform: LeetCode

Approach:
Binary Search on ship capacity.
Check how many days are needed for a given capacity.

Time Complexity: O(n * log(sum(weights)))
Space Complexity: O(1)
*/

class Solution {
public:
    int shipWithinDays(vector<int>& wei, int days) {
        int lo = 0, hi = 0, ans = 0;

        for (int i : wei) {
            lo = max(lo, i);   // minimum capacity
            hi += i;           // maximum capacity
        }

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int time = 1, cap = 0;

            for (int i : wei) {
                cap += i;

                if (cap > mid) {
                    time++;
                    cap = i;
                }
            }

            if (time <= days) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
