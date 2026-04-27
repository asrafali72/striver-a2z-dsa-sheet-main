/*
===========================================================
📌 Problem: Lemonade Change (LeetCode 860)

🧠 Intuition:
- Each lemonade costs $5.
- Customers pay with $5, $10, or $20.
- We must return correct change using available bills.
- Greedy idea:
      Always prioritize giving $10 + $5 for $20 (better than 3×$5).

⚙️ Approach:
1. Track count of:
      - $5 bills
      - $10 bills
2. Iterate over bills:
      - If $5 → increase count
      - If $10:
            need one $5 → decrease $5, increase $10
      - If $20:
            prefer ($10 + $5)
            else use (3 × $5)
            else → return false
3. If all customers handled → return true

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {

                if (five == 0) return false;

                five--;
                ten++;
            }
            else { // bill == 20

                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};