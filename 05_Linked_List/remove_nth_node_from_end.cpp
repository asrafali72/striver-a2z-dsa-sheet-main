/*
Problem: Remove Nth Node From End of List

Platform: LeetCode

Short Explanation:
- Count total nodes in the list.
- Find the (length - n)th node from start.
- Adjust pointers to remove the target node.
- Handle edge case when head is removed.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;

        // Count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // If head needs to be removed
        if (count == n) {
            return head->next;
        }

        // Find previous node of target
        count -= n + 1;
        temp = head;

        while (count--) {
            temp = temp->next;
        }

        // Remove node
        if (n == 1) {
            temp->next = NULL;
        } else {
            temp->next = temp->next->next;
        }

        return head;
    }
};