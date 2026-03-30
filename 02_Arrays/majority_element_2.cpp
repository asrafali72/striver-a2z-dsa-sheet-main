/*
Problem: Majority Element II
Platform: LeetCode

Approach:
Use a hash map to count the frequency of each element.
Any element appearing more than n/3 times is added to the result.
Traverse the map and collect such elements.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        unordered_map<int,int> m;

        for(int i : nums)
            m[i]++;

        int check = nums.size() / 3;

        for(auto [i, j] : m){
            if(j > check)
                ans.push_back(i);
        }

        return ans;
    }
};
