/*
===========================================================
📌 Problem: Insert Interval (LeetCode 57)

🧠 Intuition:
- Intervals are already sorted.
- We need to insert a new interval and merge overlaps.
- Three phases:
      1. Add all non-overlapping intervals before new interval
      2. Merge overlapping intervals with new interval
      3. Add remaining intervals

⚙️ Approach:
1. Traverse intervals:
      - If current interval ends before new interval starts → add to answer
2. Merge overlapping intervals:
      - Update new interval boundaries:
            start = min(...)
            end = max(...)
3. Add merged interval
4. Add remaining intervals

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

===========================================================
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // Step 1: Add non-overlapping intervals before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        // Step 3: Add merged interval
        ans.push_back(newInterval);

        // Step 4: Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};