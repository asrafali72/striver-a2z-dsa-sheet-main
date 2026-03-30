/*
Problem: Subarray Sum Equals K
Platform: LeetCode

Approach:
Use the prefix sum technique with a hash map.
While traversing the array, keep adding elements to a running sum.
If (current_sum - k) exists in the map, it means a subarray with sum k
ends at the current index. Add the frequency of (current_sum - k)
to the answer. Store the frequency of each prefix sum in the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        m[0]++;

        int sum = 0, ans = 0;

        for(int i : nums){

            sum += i;

            if(m.find(sum - k) != m.end()){
                ans += m[sum - k];
            }

            m[sum]++;
        }

        return ans;
    }
};
