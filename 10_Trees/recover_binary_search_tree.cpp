/*
===========================================================
📌 Problem: Recover Binary Search Tree (LeetCode 99)

🧠 Intuition:
- Inorder traversal of BST should be sorted.
- If two nodes are swapped → there will be violations:
      Case 1: Adjacent swap → one violation
      Case 2: Non-adjacent swap → two violations
- Track the misplaced nodes during inorder traversal.

⚙️ Approach (Optimal - O(1) extra space):
1. Perform inorder traversal.
2. Maintain:
      - prev → previous node
      - first → first misplaced node
      - second → second misplaced node
3. When prev->val > curr->val:
      - first = prev (first time)
      - second = curr (update always)
4. After traversal:
      swap(first->val, second->val)

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

    TreeNode *first = NULL, *second = NULL, *prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect swapped nodes
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        // Swap values
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};