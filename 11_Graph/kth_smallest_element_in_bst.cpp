/*
===========================================================
📌 Problem: Kth Smallest Element in a BST (LeetCode 230)

🧠 Intuition:
- Inorder traversal of BST gives sorted order.
- k-th smallest element = k-th element in inorder traversal.

⚙️ Approach 1 (Your Approach - Inorder + Array):
1. Perform inorder traversal.
2. Store elements in vector.
3. Return ans[k-1].

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

-----------------------------------------------------------
⚙️ Approach 2 (Optimal - No Extra Space):
1. Perform inorder traversal.
2. Keep count of visited nodes.
3. When count == k → return value immediately.

⏱️ Time Complexity: O(H + K)
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

    // Optimal DFS approach
    int dfs(TreeNode* root, int& k) {

        if (!root) return -1;

        // Traverse left
        int left = dfs(root->left, k);
        if (left != -1) return left;

        // Visit node
        k--;
        if (k == 0) return root->val;

        // Traverse right
        return dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};