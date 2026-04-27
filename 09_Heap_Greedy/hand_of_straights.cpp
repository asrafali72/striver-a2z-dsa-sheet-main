/*
===========================================================
📌 Problem: Hand of Straights (LeetCode 846)

🧠 Intuition:
- We need to divide cards into groups of size `gr` such that:
      each group contains consecutive numbers.
- Greedy idea:
      Always start forming a group from the smallest available card.

⚙️ Approach:
1. Sort the array.
2. Count frequency using hashmap.
3. Iterate through sorted hand:
      - If current number is still available:
            try to build a group of size `gr`
      - Check consecutive elements (i, i+1, ..., i+gr-1)
      - If any number missing → return false
      - Otherwise decrease frequency
4. If all groups formed successfully → return true

⏱️ Time Complexity: O(N log N)
📦 Space Complexity: O(N)

===========================================================
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gr) {

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;

        // Count frequency
        for (int x : hand) freq[x]++;

        // Try forming groups
        for (int x : hand) {

            if (freq[x] > 0) {

                for (int j = 0; j < gr; j++) {

                    if (freq[x + j] == 0)
                        return false;

                    freq[x + j]--;
                }
            }
        }

        return true;
    }
};