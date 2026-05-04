/*
===========================================================
📌 Problem: Binary Tree Postorder Traversal (LeetCode 145)

🧠 Intuition:
- Postorder traversal order:
      Left → Right → Root
- Visit children first, then process the node.

⚙️ Approach:
1. Create helper function:
      - If node is NULL → return
      - Recurse left subtree
      - Recurse right subtree
      - Add node value to result
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
        if (!root) return;

        dfs(root->left, ans);    // Left
        dfs(root->right, ans);   // Right
        ans.push_back(root->val); // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        dfs(root, ans);

        return ans;
    }
};