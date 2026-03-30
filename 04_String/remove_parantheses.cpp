/*
Problem: Remove Outermost Parentheses

Platform: LeetCode

Problem Statement:
Given a valid parentheses string s, remove the outermost parentheses 
of every primitive substring.

Example:
Input: s = "(()())(())"
Output: "()()()"

Short Explanation:
We track the depth of parentheses using a stack.
- The first '(' of a group is outer → skip it.
- The last ')' of a group is outer → skip it.
- Add all inner parentheses to the result.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(char i : s){
            if(st.empty()){
                st.push(i);
            }
            else if(i == '('){
                st.push(i);
                ans += '(';
            }
            else{
                if(st.size() != 1) ans += ')';
                st.pop();
            }
        } 
        return ans; 
    }
};