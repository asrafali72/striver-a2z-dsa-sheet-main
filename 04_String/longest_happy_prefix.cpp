/*
Problem: Longest Happy Prefix

Platform: LeetCode

Short Explanation:
- Build LPS (Longest Prefix Suffix) array using KMP.
- Last value of LPS gives length of longest prefix = suffix.
- Return substring of that length.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string longestPrefix(string s) {

        vector<int> v(s.size(), 0);
        int i = 0, j = 1;

        while(j < s.size()){
            if(s[i] == s[j]){
                i++;
                v[j] = i;
                j++;
            }
            else{
                if(i != 0) i = v[i - 1];
                else{
                    v[j] = 0;
                    j++;
                }
            }
        }

        return s.substr(0, v[s.size() - 1]);
    }
};