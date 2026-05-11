/*
===========================================================
📌 Problem: Delete Node in a BST (LeetCode 450)

🧠 Intuition:
- Maintain BST property after deletion.
- 3 cases:
      1. Node is a leaf → delete directly
      2. Node has one child → replace with child
      3. Node has two children →
            replace with inorder predecessor (max in left)
            OR inorder successor (min in right)

⚙️ Approach:
1. Traverse BST to find node:
      - key < root → go left
      - key > root → go right
2. When found:
      - Handle 3 cases:
            • No child → return NULL
            • One child → return that child
            • Two children:
                  → find max in left subtree
                  → attach right subtree
                  → return new root

⏱️ Time Complexity: O(H)
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {

            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* pred = root->left;

            // Find inorder predecessor (max in left)
            while (pred->right) {
                pred = pred->right;
            }

            // Attach right subtree
            pred->right = root->right;

            TreeNode* newRoot = root->left;
            delete root;

            return newRoot;
        }

        return root;
    }
};