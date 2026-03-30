/*
Problem: 3Sum
Platform: LeetCode

Approach:
Sort the array and fix one element. Then use two pointers (lo, hi)
to find pairs such that the total sum becomes zero. Skip duplicate
elements to avoid repeating triplets.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){

            if(i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int lo = i + 1, hi = nums.size() - 1;

            while(lo < hi){

                int sum = nums[i] + nums[lo] + nums[hi];

                if(sum == 0){

                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;

                    lo++;
                    hi--;
                }
                else if(sum > 0){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }

        return ans;
    }
};
