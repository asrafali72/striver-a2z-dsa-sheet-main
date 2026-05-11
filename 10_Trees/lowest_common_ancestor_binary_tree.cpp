/*
===========================================================
📌 Problem: Lowest Common Ancestor of a Binary Tree (LeetCode 236)

🧠 Intuition:
- LCA = lowest node that has both p and q as descendants.
- If current node matches p or q → return it.
- If both left & right return non-null → current node is LCA.

⚙️ Approach:
1. Base Case:
      - If root == NULL → return NULL
      - If root == p or q → return root
2. Recurse on left and right:
      left = LCA(root->left)
      right = LCA(root->right)
3. If both non-null → return root
4. Else return non-null one

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) return NULL;

        // If current node is p or q
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null → this is LCA
        if (left && right) return root;

        // Otherwise return non-null side
        return left ? left : right;
    }
};