/*
Problem: Rotate String

Platform: LeetCode

Short Explanation:
- Try every possible rotation starting index.
- If a character matches goal[0], check full rotation.
- Compare rotated string with goal.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    bool f(string s, string goal, int i){
        int j = 0;

        for(int k = i; k < s.size(); k++){
            if(s[k] != goal[j]) return false;
            j++;
        }

        for(int k = 0; k < i; k++){
            if(s[k] != goal[j]) return false;
            j++;
        }

        return true;
    }

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == goal[0]){
                if(f(s, goal, i)) return true;
            }
        }

        return false;
    }
};