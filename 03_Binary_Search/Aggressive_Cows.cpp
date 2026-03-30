/*
Problem: Aggressive Cows
Platform: GFG

Approach:
Binary Search on minimum distance.
Greedy placement of cows.

Time Complexity: O(n log n + n log(maxDistance))
Space Complexity: O(1)
*/

class Solution {
public:

    bool canPlace(vector<int> &sta, int k, int dist) {
        int count = 1;
        int lastPos = sta[0];

        for (int i = 0; i < sta.size(); i++) {
            if (sta[i] - lastPos >= dist) {
                count++;
                lastPos = sta[i];
            }

            if (count >= k) return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &sta, int k) {
        sort(sta.begin(), sta.end());

        int lo = 1, hi = sta.back() - sta.front();
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canPlace(sta, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
