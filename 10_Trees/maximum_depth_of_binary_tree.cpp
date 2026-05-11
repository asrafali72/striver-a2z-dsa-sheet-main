/*
===========================================================
📌 Problem: Maximum Depth of Binary Tree (LeetCode 104)

🧠 Intuition:
- Depth = number of nodes along the longest path from root to leaf.
- Use DFS to track current depth and update maximum.

⚙️ Approach (DFS with parameter):
1. Traverse tree recursively.
2. Pass current depth (level).
3. At each node:
      - Update maxDepth = max(maxDepth, current depth)
4. Recurse left and right with depth + 1
5. Return maxDepth

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)
      H = height of tree

💡 Alternative (Cleaner):
      return 1 + max(leftDepth, rightDepth)

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

    void dfs(TreeNode* root, int &maxDepth, int depth) {
        if (root == NULL) return;

        maxDepth = max(maxDepth, depth);

        dfs(root->left, maxDepth, depth + 1);
        dfs(root->right, maxDepth, depth + 1);
    }

    int maxDepth(TreeNode* root) {

        int maxDepth = 0;
        dfs(root, maxDepth, 1);

        return maxDepth;
    }
};