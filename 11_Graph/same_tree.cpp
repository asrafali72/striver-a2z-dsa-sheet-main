/*
===========================================================
📌 Problem: Same Tree (LeetCode 100)

🧠 Intuition:
- Two trees are same if:
      1. Structure is identical
      2. Node values are equal
- Compare nodes recursively.

⚙️ Approach:
1. Base Cases:
      - If both NULL → true
      - If one NULL → false
2. Check current node values
3. Recursively check:
      left subtree AND right subtree

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

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both NULL
        if (p == NULL && q == NULL) return true;

        // One NULL
        if (p == NULL || q == NULL) return false;

        // Value mismatch
        if (p->val != q->val) return false;

        // Check subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};