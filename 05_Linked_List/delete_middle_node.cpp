/*
Problem: Delete the Middle Node of a Linked List

Platform: LeetCode

Short Explanation:
- Use slow & fast pointers to find middle node.
- Slow reaches the middle when fast reaches end.
- Copy next node's value into middle node.
- Delete next node by adjusting pointers.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Edge cases
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        if (head->next->next == NULL) {
            head->next = NULL;
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node
        slow->val = slow->next->val;
        slow->next = slow->next->next;

        return head;
    }
};