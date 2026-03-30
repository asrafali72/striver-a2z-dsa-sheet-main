/*
Problem: Two Sum
Platform: LeetCode

Approach:
Use a hash map to store the elements and their indices while traversing
the array. For each element nums[i], check if (target - nums[i]) already
exists in the map. If it exists, we have found the required pair.
Otherwise, store the current element and its index in the map.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int,int> m;

        for(int i = 0; i < nums.size(); i++){

            if(m.find(target - nums[i]) != m.end()){
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
            }

            m[nums[i]] = i;
        }

        return ans;
    }
};
