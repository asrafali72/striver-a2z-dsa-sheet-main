/*
Problem: Valid Anagram

Platform: LeetCode

Short Explanation:
- Count frequency of characters using array.
- Increment for string s, decrement for string t.
- If all values become 0 → anagram.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        vector<int> v(26, 0);

        for(char i : s){
            v[i - 'a']++;
        }

        for(char i : t){
            v[i - 'a']--;
        }

        for(int i : v){
            if(i != 0) return false;
        }

        return true; 
    }
};