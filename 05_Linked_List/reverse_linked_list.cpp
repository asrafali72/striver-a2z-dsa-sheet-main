/*
Problem: Reverse Linked List

Platform: LeetCode

Short Explanation:
- Use three pointers (prev, current, next).
- Traverse the list and reverse links one by one.
- Make current node point to previous.
- Move all pointers forward.
- At the end, prev becomes new head.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* next1 = head;

        while (next1 != NULL) {
            ListNode* temp = next1;   // store current node
            next1 = next1->next;      // move to next node
            temp->next = prev;        // reverse link
            prev = temp;              // move prev forward
        }

        return prev; // new head
    }
};