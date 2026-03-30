/*
Problem: Isomorphic Strings

Platform: LeetCode

Short Explanation:
- Use two hash maps for mapping both directions.
- Ensure one-to-one mapping between characters.
- If mismatch occurs → return false.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_map<char, char> m1;

        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) != m.end() && m[s[i]] != t[i])
                return false;
            else
                m[s[i]] = t[i];

            if(m1.find(t[i]) != m1.end() && m1[t[i]] != s[i])
                return false;
            else
                m1[t[i]] = s[i];
        }

        return true;
    }
};