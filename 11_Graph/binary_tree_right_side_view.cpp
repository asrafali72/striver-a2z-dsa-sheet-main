/*
===========================================================
📌 Problem: Binary Tree Right Side View (LeetCode 199)

🧠 Intuition:
- From the right side, we see the last node of each level.
- Use level order traversal (BFS).
- At each level, capture the last node.

⚙️ Approach:
1. Use queue for BFS.
2. For each level:
      - Traverse all nodes
      - Track last node value
3. Add last node of each level to result.

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(N)

💡 Alternative:
- DFS (Right → Left) and take first node at each depth.

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // If it's the last node of this level
                if (i == size - 1) {
                    ans.push_back(node->val);
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ans;
    }
};