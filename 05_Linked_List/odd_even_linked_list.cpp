/*
Problem: Odd Even Linked List

Platform: LeetCode

Short Explanation:
- Separate nodes based on position (odd and even index).
- Traverse list and move even nodes to the end.
- Maintain order of odd and even nodes.
- Return modified head.

Time Complexity: O(n)
Space Complexity: O(1)  // (your approach uses new nodes, but logically linear traversal)
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL) return head;

        ListNode* last = head;
        ListNode* ans = head;
        int count = 1;

        // Find last node and length
        while (last->next != NULL) {
            last = last->next;
            count++;
        }

        // Rearrange nodes
        while (count > 1) {
            ListNode* temp = new ListNode(head->next->val); // create even node copy
            last->next = temp;
            last = last->next;

            temp = head->next;
            head->next = head->next->next; // remove even node
            delete(temp);

            head = head->next; // move to next odd node
            count -= 2;
        }

        return ans;
    }
};