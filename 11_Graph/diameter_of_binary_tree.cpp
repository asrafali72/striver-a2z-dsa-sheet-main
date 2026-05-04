/*
===========================================================
📌 Problem: Diameter of Binary Tree (LeetCode 543)

🧠 Intuition:
- Diameter = longest path between any two nodes.
- Path may or may not pass through root.
- At each node:
      longest path through it = leftHeight + rightHeight

⚙️ Approach:
1. Use DFS to calculate height of each subtree.
2. At each node:
      - Compute left height
      - Compute right height
      - Update diameter = max(diameter, left + right)
3. Return height = 1 + max(left, right)

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)

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

    int diameter = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Update diameter
        diameter = max(diameter, left + right);

        // Return height
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        dfs(root);
        return diameter;
    }
};