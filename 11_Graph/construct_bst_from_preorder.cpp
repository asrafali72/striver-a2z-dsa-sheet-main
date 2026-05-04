/*
===========================================================
📌 Problem: Construct Binary Search Tree from Preorder Traversal (LeetCode 1008)

🧠 Intuition:
- Preorder = Root → Left → Right
- Use BST property with bounds:
      each node must lie within (lo, hi)
- Build tree while maintaining valid range.

⚙️ Approach:
1. Maintain index `i` for preorder traversal.
2. For each value:
      - If it lies outside (lo, hi) → return NULL
3. Create node:
      - Increment index
4. Recursively build:
      - left → (lo, root->val)
      - right → (root->val, hi)

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

    TreeNode* build(vector<int>& pre, int& i, int low, int high) {

        // Out of bounds or finished
        if (i == pre.size() || pre[i] < low || pre[i] > high) {
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[i++]);

        root->left = build(pre, i, low, root->val);
        root->right = build(pre, i, root->val, high);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0;
        return build(preorder, i, INT_MIN, INT_MAX);
    }
};