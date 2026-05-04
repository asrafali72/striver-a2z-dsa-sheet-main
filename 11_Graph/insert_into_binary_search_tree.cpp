/*
===========================================================
📌 Problem: Insert into a Binary Search Tree (LeetCode 701)

🧠 Intuition:
- In BST:
      left < root < right
- Insert the value at the correct position while preserving BST property.
- No need to rebuild the entire tree.

⚙️ Approach (Optimal):
1. If root is NULL → create new node.
2. Traverse:
      - If val < root → go left
      - Else → go right
3. Insert at the correct NULL position.
4. Return root.

⏱️ Time Complexity: O(H)
📦 Space Complexity: O(H) (recursion) / O(1) iterative

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if (root == NULL) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};