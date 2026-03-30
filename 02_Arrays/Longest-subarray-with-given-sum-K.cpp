/*
Problem: Longest Subarray with Sum K
Platform: GeeksforGeeks

Approach:
Use the prefix sum technique with a hash map.
Traverse the array and keep adding elements to a running sum.
If (sum - k) exists in the map, it means a subarray with sum k
exists between the stored index and the current index.
Update the maximum length accordingly.
Store the first occurrence of each prefix sum in the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        unordered_map<int,int> m;
        m[0] = -1;

        int sum = 0, maxi = 0;

        for(int i = 0; i < arr.size(); i++){

            sum += arr[i];

            if(m.find(sum - k) != m.end())
                maxi = max(maxi, i - m[sum - k]);

            if(m.find(sum) == m.end())
                m[sum] = i;
        }

        return maxi;
    }
};
