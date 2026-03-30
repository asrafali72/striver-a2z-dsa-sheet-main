/*
Problem: Minimum Add to Make Parentheses Valid

Platform: LeetCode

Short Explanation:
- Count unmatched '(' and ')'.
- For ')':
  - If matching '(' exists → cancel it.
  - Else → count as extra ')'.
- Result = unmatched '(' + unmatched ')'.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {

        int l = 0, r = 0;

        for(char i : s){
            if(i == '(') l++;
            else{
                if(l > 0) l--;
                else r++;
            }
        }

        return l + r;
    }
};