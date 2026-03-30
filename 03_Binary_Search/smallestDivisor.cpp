/*
Problem: Find the Smallest Divisor Given a Threshold
Platform: LeetCode

Approach:
Binary Search on divisor.
Check if sum of ceil(nums[i]/divisor) <= threshold.

Time Complexity: O(n * log(max(nums)))
Space Complexity: O(1)
*/

class Solution {
public:

    int computeSum(int mid, vector<int> nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] / mid;
            if (nums[i] % mid != 0) sum++;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 0, ans = 1;

        for (int i : nums)
            hi = max(hi, i);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int sum = computeSum(mid, nums);

            if (sum <= threshold) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};
