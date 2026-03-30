/*
Problem: Largest Odd Number in String

Platform: LeetCode

Short Explanation:
- Traverse from the end of the string.
- Find the first odd digit.
- Return substring till that index.
- If no odd digit → return empty string.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() != 0){
            int a = num[num.size() - 1] - '0';

            if(a % 2 != 0) break;

            num.pop_back();
        }
        return num;
    }
};