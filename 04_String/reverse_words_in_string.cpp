/*
Problem: Reverse Words in a String

Platform: LeetCode

Short Explanation:
- Extract words from string
- Store in vector
- Reverse order and join with space

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        vector<string> v;
        int i = 0;

        while(i < s.size()){
            string temp = "";

            while(i < s.size() && s[i] != ' '){
                temp += s[i];
                i++;
            }

            if(temp.size() != 0)
                v.push_back(temp);

            i++;
        }

        for(int i = v.size() - 1; i >= 0; i--){
            ans += v[i];
            ans += ' ';
        }

        ans.pop_back();
        return ans;
    }
};