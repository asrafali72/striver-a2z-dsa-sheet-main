/*
Problem: Leaders in an Array
Platform: GeeksforGeeks

Approach:
Traverse the array from right to left while maintaining the maximum
element seen so far. If the current element is greater than or equal
to the current maximum, it is a leader because no element to its right
is greater than it. Add such elements to the result and finally reverse
the result array.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {

        vector<int> ans;
        int maxi = INT_MIN;

        for(int i = arr.size() - 1; i >= 0; i--){

            if(maxi <= arr[i]){
                maxi = arr[i];
                ans.push_back(arr[i]);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
