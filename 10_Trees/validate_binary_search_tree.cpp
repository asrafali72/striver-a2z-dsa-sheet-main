/*
===========================================================
📌 Problem: Validate Binary Search Tree (LeetCode 98)

🧠 Intuition:
- BST property:
      left < root < right (for every node)
- Instead of storing inorder:
      validate using value range (min, max).

⚙️ Approach (Optimal):
1. Pass valid range for each node:
      - root → (-∞, +∞)
2. For each node:
      - value must lie in (min, max)
3. Recurse:
      - left → (min, root->val)
      - right → (root->val, max)

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

    bool dfs(TreeNode* root, long long minVal, long long maxVal) {

        if (!root) return true;

        // Check BST property
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return dfs(root->left, minVal, root->val) &&
               dfs(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {

        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};