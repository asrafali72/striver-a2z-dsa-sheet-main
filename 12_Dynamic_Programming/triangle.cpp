// File: triangle.cpp

/*
Approach:
- Use Bottom-Up Dynamic Programming
- Start from second last row
- Add minimum of downward and diagonal values
- Final answer will be stored at top cell

Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        for (int i = n - 2; i >= 0; --i) {

            for (int j = 0; j < triangle[i].size(); ++j) {

                triangle[i][j] +=
                    min(triangle[i + 1][j],
                        triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};