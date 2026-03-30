
/*
Problem: Delete Node in a Linked List

Platform: LeetCode

Short Explanation:
- We are NOT given the head.
- Copy value of next node into current node.
- Delete next node by skipping it.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};