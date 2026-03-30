/*
Problem: Longest Consecutive Sequence
Platform: LeetCode

Approach:
Insert all elements into an unordered set for O(1) lookups.
Then iterate through the set and check for the start of a sequence
(i.e., when i-1 does not exist in the set). From that starting point,
keep checking the next consecutive numbers (i+1, i+2, ...) and count
the length of the sequence. Track the maximum sequence length.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> m;
        int count = 0;

        for(int i : nums)
            m.insert(i);

        for(int i : m){

            if(m.find(i - 1) == m.end()){

                int c = 1;
                int e = i + 1;

                while(m.find(e) != m.end()){
                    c++;
                    e++;
                }

                count = max(count, c);
            }
        }

        return count;
    }
};
