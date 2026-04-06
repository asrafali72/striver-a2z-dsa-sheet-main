/*
Problem: Middle of the Linked List

Platform: LeetCode

Short Explanation:
- Use two pointers (slow & fast).
- Slow moves 1 step, fast moves 2 steps.
- When fast reaches end, slow will be at middle.
- Return slow pointer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps
        }

        return slow; // middle node
    }
};