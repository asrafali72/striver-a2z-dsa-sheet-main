/*
Problem: Sort Characters By Frequency

Platform: LeetCode

Short Explanation:
- Count frequency using hashmap.
- Store (frequency, character) in vector.
- Sort vector in descending order.
- Build result string using frequencies.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> m;

        for(char i : s){
            m[i]++;
        }

        vector<pair<int, char>> v;

        for(auto [ch, freq] : m){
            v.push_back({freq, ch});
        }

        sort(v.begin(), v.end());

        string ans = "";

        for(int i = v.size() - 1; i >= 0; i--){
            auto [freq, ch] = v[i];

            while(freq--){
                ans += ch;
            }
        }

        return ans;
    }
};