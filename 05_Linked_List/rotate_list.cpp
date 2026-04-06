/*
Problem: Rotate List

Platform: LeetCode

Short Explanation:
- Find length of list.
- Connect last node to head (make circular).
- Find new tail at (length - k % length - 1).
- Break the circle and return new head.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL) return NULL;

        int a = 1;
        ListNode* temp = head;

        // Find length and last node
        while (temp->next != NULL) {
            a++;
            temp = temp->next;
        }

        k = k % a;
        if (k == 0) return head;

        // Find new tail
        a = a - k - 1;
        ListNode* temp2 = head;

        while (a--) {
            temp2 = temp2->next;
        }

        // Rearrange pointers
        ListNode* ans = temp2->next;
        temp2->next = NULL;
        temp->next = head;

        return ans;
    }
};