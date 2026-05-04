/*
===========================================================
📌 Problem: Search in a Binary Search Tree (LeetCode 700)

🧠 Intuition:
- In BST:
      left < root < right
- Use this property to decide direction:
      val < root → go left
      val > root → go right

⚙️ Approach:
1. Start from root.
2. While node is not NULL:
      - If node->val == target → return node
      - If target < node->val → go left
      - Else → go right
3. If not found → return NULL

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root != NULL) {

            if (root->val == val) {
                return root;
            }
            else if (val < root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return NULL;
    }
};