// File: maximal_rectangle.cpp

/*
Approach:
- Convert each row into histogram heights
- For every row:
    find Largest Rectangle in Histogram
- Use Monotonic Stack to find:
    1. Previous Smaller Element
    2. Next Smaller Element

Time Complexity: O(n * m)
Space Complexity: O(m)
*/

class Solution {
public:

    int largestHistogram(vector<int>& heights) {

        int n = heights.size();

        stack<int> st, st2;

        vector<int> left(n, -1);
        vector<int> right(n, n);

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   heights[st.top()] >= heights[i]) {

                st.pop();
            }

            if (!st.empty())
                left[i] = st.top();

            st.push(i);
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st2.empty() &&
                   heights[st2.top()] >= heights[i]) {

                st2.pop();
            }

            if (!st2.empty())
                right[i] = st2.top();

            st2.push(i);
        }

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            maxi = max(
                maxi,
                heights[i] *
                (right[i] - left[i] - 1)
            );
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }

            ans = max(ans,
                      largestHistogram(heights));
        }

        return ans;
    }
};