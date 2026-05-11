/*
===========================================================
📌 Problem: Balanced Binary Tree (LeetCode 110)

🧠 Intuition:
- A tree is balanced if:
      |height(left) - height(right)| ≤ 1 for every node.
- While calculating height, we can simultaneously check balance.

⚙️ Approach (Optimized DFS):
1. Use postorder traversal (Left → Right → Root).
2. For each node:
      - Get left height
      - Get right height
      - If difference > 1 → mark unbalanced
3. Return height = 1 + max(left, right)

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)

💡 Optimization:
- Combine height + balance check in single traversal.

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

    int dfs(TreeNode* root, bool &isBal) {
        if (root == NULL) return 0;

        int left = dfs(root->left, isBal);
        int right = dfs(root->right, isBal);

        // Check balance condition
        if (abs(left - right) > 1) {
            isBal = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        bool isBal = true;
        dfs(root, isBal);

        return isBal;
    }
};