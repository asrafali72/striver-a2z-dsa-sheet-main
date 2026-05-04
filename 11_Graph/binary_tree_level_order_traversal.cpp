/*
===========================================================
📌 Problem: Binary Tree Level Order Traversal (LeetCode 102)

🧠 Intuition:
- Traverse tree level by level (BFS).
- Use a queue to process nodes in FIFO order.
- For each level, process all nodes currently in queue.

⚙️ Approach:
1. If root is NULL → return empty result.
2. Push root into queue.
3. While queue is not empty:
      - Get current level size
      - Traverse all nodes in this level:
            → pop node
            → add value to current level list
            → push left and right children (if exist)
      - Add level list to result
4. Return result

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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            while (size--) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};