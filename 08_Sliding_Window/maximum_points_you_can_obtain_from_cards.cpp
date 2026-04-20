/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Maximum Points You Can Obtain from Cards

🧠 Intuition:
- We can take k cards from either start or end.
- Equivalent idea:
      👉 Take some from left + remaining from right
- Try all combinations using sliding window.

⚙️ Approach:
1. Take first k elements → initial sum.
2. Gradually replace elements from left with elements from right.
3. Track maximum sum.

⏱️ Time Complexity: O(k)
📦 Space Complexity: O(1)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        // Step 1: Take first k elements
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int maxi = sum;

        int left = k - 1;
        int right = n - 1;

        // Step 2: Slide window
        while (left >= 0) {

            sum += cardPoints[right]; // add from right
            sum -= cardPoints[left];  // remove from left

            maxi = max(maxi, sum);

            right--;
            left--;
        }

        return maxi;
    }
};