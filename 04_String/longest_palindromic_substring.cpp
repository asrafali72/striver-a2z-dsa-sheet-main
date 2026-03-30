/*
Problem: Longest Palindromic Substring

Platform: LeetCode

Short Explanation:
- Try every index as center.
- Expand for odd (i,i) and even (i,i+1).
- Track longest palindrome found.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    string f(string s, int lo, int hi){
        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
            lo--;
            hi++;
        }

        return s.substr(lo + 1, hi - lo - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            string odd = f(s, i, i);
            string even = f(s, i, i + 1);

            if(ans.size() < odd.size()) ans = odd;
            if(ans.size() < even.size()) ans = even;
        }

        return ans;
    }
};