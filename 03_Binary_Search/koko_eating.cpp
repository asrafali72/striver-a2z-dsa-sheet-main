/*
Problem: Koko Eating Bananas
Platform: LeetCode

Approach:
Binary Search on Answer (Eating Speed).
If required hours > h → increase speed.
Else → try smaller speed.

Time Complexity: O(n * log(max(piles)))
Space Complexity: O(1)
*/

class Solution {
public:

    long long hoursRequired(vector<int>& piles, int mid) {
        long long count = 0;

        for (int i : piles) {
            if (mid < i) {
                count += (i / mid);
                if (i % mid != 0) count++;
            } 
            else count++;
        }

        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 0;

        for (int i : piles)
            hi = max(hi, i);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (hoursRequired(piles, mid) > h)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }
};
