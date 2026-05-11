/*
===========================================================
📌 Problem: Binary Tree Inorder Traversal (LeetCode 94)

🧠 Intuition:
- Inorder traversal follows:
      Left → Root → Right
- Use an iterative approach with a stack to simulate recursion.

⚙️ Approach:
1. Initialize:
      - Stack for nodes
      - Pointer `curr = root`
2. Traverse:
      - Go as left as possible → push nodes into stack
      - When NULL:
            → pop from stack
            → add value to result
            → move to right subtree
3. Repeat until stack empty and curr is NULL

⏱️ Time Complexity: O(N)
📦 Space Complexity: O(H)
      H = height of tree (stack space)

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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            // Go to leftmost node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        return ans;
    }
};