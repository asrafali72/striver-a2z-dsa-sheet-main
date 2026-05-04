/*
===========================================================
📌 Problem: Two Sum IV - Input is a BST (LeetCode 653)

🧠 Intuition:
- Inorder traversal of BST gives sorted array.
- Then problem becomes:
      Two Sum in sorted array → use two pointers.

⚙️ Approach 1 (Your Approach - Inorder + Two Pointers):
1. Perform inorder traversal → sorted vector.
2. Use two pointers:
      lo = 0, hi = n-1
3. While lo < hi:
      - sum = v[lo] + v[hi]
      - if sum == k → true
      - if sum < k → lo++
      - else → hi--
4. If no pair → false

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

-----------------------------------------------------------
⚙️ Approach 2 (Optimal - HashSet):
1. Traverse tree (DFS/BFS).
2. For each node:
      - Check if (k - node->val) exists in set
      - If yes → return true
      - Else insert current value
3. Continue traversal

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

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

    bool dfs(TreeNode* root, unordered_set<int>& seen, int k) {
        if (!root) return false;

        if (seen.count(k - root->val)) return true;

        seen.insert(root->val);

        return dfs(root->left, seen, k) ||
               dfs(root->right, seen, k);
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> seen;
        return dfs(root, seen, k);
    }
};