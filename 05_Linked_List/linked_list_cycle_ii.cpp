/*
Problem: Linked List Cycle II

Platform: LeetCode

Short Explanation:
- Use slow & fast pointers to detect cycle.
- If they meet → cycle exists.
- Move one pointer to head.
- Move both one step at a time.
- The meeting point is the start of the cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;

        // Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) {
                count++;
                break;
            }
        }

        if (count == 0) return NULL; // no cycle

        // Find starting node of cycle
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return head; // start of cycle
    }
};