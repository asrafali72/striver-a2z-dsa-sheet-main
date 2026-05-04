/*
===========================================================
📌 Problem: Binary Tree Postorder Traversal (LeetCode 145)

🧠 Intuition:
- Postorder traversal follows:
      Left → Right → Root
- Recursively process left subtree, then right subtree,
  and finally the current node.

⚙️ Approach:
1. Create helper function:
      - If node is NULL → return
      - Recurse on left subtree
      - Recurse on right subtree
      - Add node value to result
2. Call helper with root

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)
      H = height of tree (recursion stack)

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

        dfs(root->left, ans);   // Left
        dfs(root->right, ans);  // Right
        ans.push_back(root->val); // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        dfs(root, ans);

        return ans;
    }
};