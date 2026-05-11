/*
===========================================================
📌 Problem: Symmetric Tree (LeetCode 101)

🧠 Intuition:
- Tree is symmetric if left subtree is a mirror of right subtree.
- Compare nodes in mirror fashion:
      left->left ↔ right->right
      left->right ↔ right->left

⚙️ Approach:
1. Create helper function isMirror(a, b):
      - If both NULL → true
      - If one NULL → false
      - If values differ → false
2. Recursively check:
      isMirror(a->left, b->right) &&
      isMirror(a->right, b->left)
3. Call with (root->left, root->right)

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

    bool isMirror(TreeNode* a, TreeNode* b) {

        // Both NULL
        if (a == NULL && b == NULL) return true;

        // One NULL
        if (a == NULL || b == NULL) return false;

        // Value mismatch
        if (a->val != b->val) return false;

        // Mirror check
        return isMirror(a->left, b->right) &&
               isMirror(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL) return true;

        return isMirror(root->left, root->right);
    }
};