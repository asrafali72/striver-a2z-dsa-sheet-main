/*
Problem: Maximum Nesting Depth of the Parentheses

Platform: LeetCode

Short Explanation:
- Increase depth on '('
- Decrease depth on ')'
- Track maximum depth reached

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {

        int count = 0, maxi = 0;

        for(char i : s){
            if(i == '('){
                count++;
                maxi = max(maxi, count);
            }
            else if(i == ')'){
                count--;
            }
        }

        return maxi;
    }
};