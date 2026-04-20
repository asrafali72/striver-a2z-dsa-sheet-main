/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Asteroid Collision

🧠 Intuition:
- Positive → moving right
- Negative → moving left
- Collision happens only when:
      stack top > 0 AND current < 0
- Resolve collisions using stack:
      - Smaller asteroid explodes
      - Equal → both explode
      - Larger survives

⚙️ Approach:
1. Traverse all asteroids.
2. If positive → push to stack.
3. If negative:
      - Compare with stack top while collision possible.
      - Pop smaller elements.
      - If equal → pop and stop.
      - If stack empty → add to answer.
4. Combine remaining stack + negative survivors.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {

        stack<int> st;
        vector<int> ans;

        for (int i : ast) {

            // Case 1: Moving right → push
            if (i >= 0) {
                st.push(i);
            }

            // Case 2: Moving left → possible collision
            else {
                int a = -i;

                // Remove smaller asteroids
                while (!st.empty() && st.top() < a) {
                    st.pop();
                }

                // Equal size → both destroyed
                if (!st.empty() && st.top() == a) {
                    st.pop();
                }

                // No collision → survives
                else if (st.empty()) {
                    ans.push_back(i);
                }
            }
        }

        // Add remaining stack elements
        int k = ans.size();

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Reverse only stack part
        reverse(ans.begin() + k, ans.end());

        return ans;
    }
};