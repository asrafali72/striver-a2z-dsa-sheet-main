/*
Problem: Valid Parentheses

Platform: LeetCode

Short Explanation:
- Given a string containing '(', ')', '{', '}', '[', ']',
  check if the string is valid.
- A string is valid if:
    - Every opening bracket has a matching closing bracket.
    - Brackets are closed in the correct order.
- Use a stack:
    - Push opening brackets.
    - For closing brackets, check top and pop if valid.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:

    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Push opening brackets
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {

                // If stack empty → invalid
                if (st.empty()) return false;

                // Check matching pairs
                if (st.top() == '(' && ch == ')') {
                    st.pop();
                }
                else if (st.top() == '[' && ch == ']') {
                    st.pop();
                }
                else if (st.top() == '{' && ch == '}') {
                    st.pop();
                }
                else return false;
            }
        }

        // If stack empty → valid
        return st.empty();
    }
};