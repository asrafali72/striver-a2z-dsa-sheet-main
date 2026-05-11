/*
===========================================================
📌 Problem: Maximum Width of Binary Tree (LeetCode 662)

🧠 Intuition:
- Width = distance between leftmost and rightmost nodes at a level.
- Treat tree like a complete binary tree:
      left index = 2*i
      right index = 2*i + 1
- Use indexing to measure width correctly even with gaps.

⚙️ Approach:
1. Use BFS with queue storing:
      (node, index)
2. For each level:
      - Normalize indices using minimum index (to avoid overflow)
      - Track first and last index
3. Width = last - first + 1
4. Update maximum width

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

===========================================================
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            long long first = 0, last = 0;
            long long minIndex = q.front().second;

            for (int i = 0; i < size; i++) {

                auto [node, idx] = q.front();
                q.pop();

                // Normalize index to prevent overflow
                idx -= minIndex;

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left) {
                    q.push({node->left, 2 * idx});
                }
                if (node->right) {
                    q.push({node->right, 2 * idx + 1});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};