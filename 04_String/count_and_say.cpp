/*
Problem: Count and Say

Platform: LeetCode

Short Explanation:
- Start with "1".
- For each iteration:
  - Count consecutive same digits.
  - Append count + digit to new string.
- Repeat n times.

Time Complexity: O(n * length of string)
Space Complexity: O(n)
*/

class Solution {
public:
    string countAndSay(int n) {

        string a = "1";

        while(--n){
            string b = "";
            char c = a[0];
            int count = 1;

            for(int i = 1; i < a.size(); i++){
                if(a[i] == c){
                    count++;
                } else {
                    b += to_string(count);
                    b += c;
                    c = a[i];
                    count = 1;
                }
            }

            b += to_string(count);
            b += c;

            a = b;
        }

        return a;
    }
};