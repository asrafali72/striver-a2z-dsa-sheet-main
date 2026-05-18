// File: minimum_path_sum.cpp

/*
Approach:
- Use Dynamic Programming
- First row and column store cumulative sums
- For remaining cells:
    grid[i][j] += min(top, left)

Time Complexity: O(m * n)
Space Complexity: O(1)
*/

class Solution {
public:

    int minPathSum(vector<vector<int>>& gr) {

        for (int i = 1; i < gr[0].size(); i++) {

            gr[0][i] =
                gr[0][i - 1] + gr[0][i];
        }

        for (int i = 1; i < gr.size(); i++) {

            gr[i][0] =
                gr[i - 1][0] + gr[i][0];
        }

        for (int i = 1; i < gr.size(); i++) {

            for (int j = 1; j < gr[0].size(); j++) {

                gr[i][j] =
                    gr[i][j] +
                    min(gr[i - 1][j],
                        gr[i][j - 1]);
            }
        }

        return gr[gr.size() - 1][gr[0].size() - 1];
    }
};