/*
Problem: Pascal's Triangle
Platform: LeetCode

Approach:
Start with the first row [1]. Each new row is built using the previous row.
The first and last elements of every row are always 1. For the middle elements,
add the two numbers above it from the previous row. Repeat this process
until the required number of rows is generated.

Time Complexity: O(n²)
Space Complexity: O(n²)
*/

class Solution {
public:
    vector<vector<int>> generate(int nums) {

        vector<int> v1;
        vector<int> v2;
        vector<vector<int>> ans;

        v1.push_back(1);
        ans.push_back(v1);

        if(nums == 1)
            return ans;

        v1.push_back(1);
        ans.push_back(v1);

        if(nums == 2)
            return ans;

        for(int i = 2; i < nums; i++){

            v2.push_back(v1[0]);

            for(int j = 0; j < v1.size() - 1; j++){
                v2.push_back(v1[j] + v1[j+1]);
            }

            v2.push_back(v1[v1.size() - 1]);

            ans.push_back(v2);

            v1.clear();
            for(int j = 0; j < v2.size(); j++){
                v1.push_back(v2[j]);
            }

            v2.clear();
        }

        return ans;
    }
};
