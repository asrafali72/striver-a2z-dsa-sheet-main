/*
===========================================================
📌 Problem: Merge Intervals (LeetCode 56)

🧠 Intuition:
- Overlapping intervals should be merged.
- After sorting:
      overlapping intervals will be adjacent.

⚙️ Approach:
1. Sort intervals based on start time.
2. Initialize current interval (start, end).
3. Traverse intervals:
      - If current end < next start:
            → no overlap → push current interval
            → move to next interval
      - Else:
            → overlap → merge by updating end
4. Push last interval

⏱️ Time Complexity: O(N log N)
📦 Space Complexity: O(N)

===========================================================
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            // No overlap
            if (end < intervals[i][0]) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                // Overlap → merge
                end = max(end, intervals[i][1]);
            }
        }

        // Push last interval
        ans.push_back({start, end});

        return ans;
    }
};