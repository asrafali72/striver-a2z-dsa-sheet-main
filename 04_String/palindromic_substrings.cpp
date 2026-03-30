/*
Problem: Palindromic Substrings

Platform: LeetCode

Short Explanation:
- Treat each index as center.
- Expand for odd (i,i) and even (i,i+1).
- Count all valid palindromes.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int f(string s, int lo, int hi){
        int count = 0;

        while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
            count++;
            lo--;
            hi++;
        }

        return count;
    }

    int countSubstrings(string s) {

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            ans += f(s, i, i);       // odd length
            ans += f(s, i, i + 1);   // even length
        }

        return ans;
    }
};