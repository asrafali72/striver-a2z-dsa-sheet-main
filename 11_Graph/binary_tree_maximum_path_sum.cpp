/*
===========================================================
📌 Problem: Binary Tree Maximum Path Sum (LeetCode 124)

🧠 Intuition:
- Path can start and end at any node.
- At each node:
      best path through node = left + right + node->val
- Ignore negative contributions (take max(0, subtree))

⚙️ Approach:
1. Use DFS:
      - Get max path from left and right
      - Ignore negative values → max(0, ...)
2. Update global maximum:
      maxi = max(maxi, left + right + root->val)
3. Return:
      max(left, right) + root->val
      (only one side allowed upward)

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

    int dfs(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        int left = max(0, dfs(root->left, maxi));
        int right = max(0, dfs(root->right, maxi));

        // Update global maximum
        maxi = max(maxi, left + right + root->val);

        // Return max path including this node
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;
        dfs(root, maxi);

        return maxi;
    }
};