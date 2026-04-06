/*
Problem: Reverse Linked List

Platform: LeetCode

Short Explanation:
- Use three pointers (prev, current, next).
- Traverse the list and reverse links.
- Point current node to previous node.
- Move pointers forward.
- Return prev as new head.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* next1 = head;

        while (next1 != NULL) {
            ListNode* temp = next1;   // current node
            next1 = next1->next;      // move ahead
            temp->next = prev;        // reverse link
            prev = temp;              // update prev
        }

        return prev; // new head
    }
};