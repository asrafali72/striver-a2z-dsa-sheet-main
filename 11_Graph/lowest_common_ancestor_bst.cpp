/*
===========================================================
📌 Problem: Lowest Common Ancestor of a BST (LeetCode 235)

🧠 Intuition:
- BST property:
      left < root < right
- If both p and q are:
      > root → LCA in right subtree
      < root → LCA in left subtree
- Otherwise → current node is LCA

⚙️ Approach:
1. Start from root.
2. If both values > root → go right
3. If both values < root → go left
4. Else → return root (split point = LCA)

⏱️ Time Complexity: O(H)
📦 Space Complexity: O(1)

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

        while (root) {

            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else {
                // Split point → LCA
                return root;
            }
        }

        return NULL;
    }
};