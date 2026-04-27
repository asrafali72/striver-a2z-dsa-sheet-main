/*
===========================================================
📌 Problem: Non-overlapping Intervals (LeetCode 435)

🧠 Intuition:
- We need to remove minimum intervals to make remaining non-overlapping.
- Equivalent to:
      maximize number of non-overlapping intervals.
- Greedy strategy:
      always pick interval with smallest end time.

⚙️ Approach:
1. Sort intervals by end time.
2. Initialize:
      prevEnd = -∞
      count = number of non-overlapping intervals
3. Traverse intervals:
      - If start >= prevEnd:
            → take interval
            → update prevEnd
            → increment count
4. Result:
      total intervals - count

⏱️ Time Complexity: O(N log N)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Sort by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int prevEnd = INT_MIN;

        for (auto &it : intervals) {

            // Non-overlapping
            if (it[0] >= prevEnd) {
                count++;
                prevEnd = it[1];
            }
        }

        // Minimum removals
        return intervals.size() - count;
    }
};