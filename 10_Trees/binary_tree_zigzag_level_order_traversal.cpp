/*
===========================================================
📌 Problem: Binary Tree Zigzag Level Order Traversal (LeetCode 103)

🧠 Intuition:
- Perform level order traversal (BFS).
- Alternate direction at each level:
      Left → Right, then Right → Left.

⚙️ Approach:
1. Use queue for BFS.
2. Maintain a boolean flag (leftToRight).
3. For each level:
      - Create a vector of size = level size
      - Fill values based on direction:
            normal index OR reverse index
4. Toggle direction after each level.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Place element based on direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);

            // Toggle direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};