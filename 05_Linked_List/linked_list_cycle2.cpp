/*
Problem: Linked List Cycle

Platform: LeetCode

Short Explanation:
- Use two pointers (slow & fast).
- Slow moves 1 step, fast moves 2 steps.
- If cycle exists → both pointers meet.
- If fast reaches NULL → no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) return true; // cycle detected
        }

        return false; // no cycle
    }
};