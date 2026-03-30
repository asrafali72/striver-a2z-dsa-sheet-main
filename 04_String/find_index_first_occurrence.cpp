/*
Problem: Find the Index of the First Occurrence in a String

Platform: LeetCode

Short Explanation:
- Use pattern matching (similar to KMP idea).
- Compare characters of needle with haystack.
- On mismatch, use previous matched length to skip checks.
- If full match found → return starting index.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int strStr(string hay, string nee) {

        vector<int> v(hay.size(), 0);
        int i = 0, j = 0;

        while(j < hay.size()){
            if(hay[j] == nee[i]){
                v[j] = i + 1;
                i++;
                j++;
            }
            else{
                if(i != 0) i = v[i - 1];
                else{
                    v[j] = 0;
                    j++;
                }
            }

            if(i == nee.size()) return j - i;
        }

        return -1;
    }
};