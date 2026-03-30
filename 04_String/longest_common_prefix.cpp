/*
Problem: Longest Common Prefix

Platform: LeetCode

Short Explanation:
- Sort the array of strings.
- Compare first and last string.
- Their common prefix is the answer.

Time Complexity: O(n log n + m)
(n = number of strings, m = length of prefix)

Space Complexity: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];

        string ans = "";
        int i = 0;

        while(i < s1.size() && i < s2.size() && s1[i] == s2[i]){
            ans += s1[i];
            i++;
        }

        return ans;
    }
};