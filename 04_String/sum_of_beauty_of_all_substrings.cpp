/*
Problem: Sum of Beauty of All Substrings

Platform: LeetCode

Short Explanation:
- Fix starting index i.
- Maintain frequency array for substring.
- For each extension, compute:
  beauty = max frequency - min frequency (non-zero).
- Add to answer.

Time Complexity: O(n^2 * 26)
Space Complexity: O(1)
*/

class Solution {
public:
    void f(vector<int>& v, int &lo, int &hi){
        for(int i : v){
            if(i != 0)
                lo = min(lo, i);
            hi = max(hi, i);
        }
    }

    int beautySum(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            vector<int> v(26, 0);

            for(int j = i; j < s.size(); j++){
                v[s[j] - 'a']++;

                int lo = INT_MAX, hi = INT_MIN;
                f(v, lo, hi);

                ans += (hi - lo);
            }
        }

        return ans;
    }
};