/*
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode

Approach:
Traverse the array while keeping track of the minimum price seen so far.
For each price, calculate the profit if we sell on that day
(price - minimum price). Update the maximum profit accordingly.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini = prices[0];
        int maxi = 0;

        for(int i : prices){
            mini = min(mini, i);
            maxi = max(maxi, i - mini);
        }

        return maxi;
    }
};
