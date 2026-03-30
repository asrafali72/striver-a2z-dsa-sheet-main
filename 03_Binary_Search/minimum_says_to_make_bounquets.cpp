/*
Problem: Minimum Days to Make m Bouquets
Platform: LeetCode

Approach:
Binary Search on number of days.
Check how many bouquets can be formed on a given day.

Time Complexity: O(n * log(max(bloomDay)))
Space Complexity: O(1)
*/

class Solution {
public:

    int countBouquets(vector<int>& blo, int mid, int k) {
        int count = 0, bouquets = 0;

        for (int i : blo) {
            if (i <= mid) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets;
    }

    int minDays(vector<int>& blo, int m, int k) {
        // Not possible case
        if ((long long)m * k > blo.size()) return -1;

        int lo = 1, hi = 0;

        for (int i : blo)
            hi = max(hi, i);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (countBouquets(blo, mid, k) >= m)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
