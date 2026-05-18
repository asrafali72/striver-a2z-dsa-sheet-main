// File: unique_paths_ii.cpp

/*
Approach:
- Use Dynamic Programming
- If cell contains obstacle, store 0
- Otherwise:
    paths = top + left
- Modify grid itself to store dp values

Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {

        if (obs[0][0] == 1)
            return 0;

        bool blocked = false;

        for (int i = 0; i < obs.size(); i++) {

            if (obs[i][0] == 1 || blocked) {
                obs[i][0] = 0;
                blocked = true;
            }
            else {
                obs[i][0] = 1;
            }

            bool rowBlocked = false;

            for (int j = 1; j < obs[0].size(); j++) {

                if (i == 0) {

                    if (obs[i][j] == 1 || rowBlocked) {
                        obs[i][j] = 0;
                        rowBlocked = true;
                    }
                    else {
                        obs[i][j] = 1;
                    }
                }
                else if (obs[i][j] == 1) {

                    obs[i][j] = 0;
                }
                else {

                    obs[i][j] =
                        obs[i][j - 1] +
                        obs[i - 1][j];
                }
            }
        }

        return obs[obs.size() - 1][obs[0].size() - 1];
    }
};