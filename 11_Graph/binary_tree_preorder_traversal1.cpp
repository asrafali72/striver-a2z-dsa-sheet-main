/*
===========================================================
📌 Problem: Binary Tree Preorder Traversal (LeetCode 144)

🧠 Intuition:
- Preorder traversal order:
      Root → Left → Right
- Visit current node first, then recursively traverse subtrees.

⚙️ Approach:
1. Create helper function:
      - If node is NULL → return
      - Add node value to result
      - Recurse on left subtree
      - Recurse on right subtree
2. Call helper with root

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)
      H = height of tree

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

    void dfs(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;

        ans.push_back(root->val);   // Root
        dfs(root->left, ans);       // Left
        dfs(root->right, ans);      // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        dfs(root, ans);

        return ans;
    }
};