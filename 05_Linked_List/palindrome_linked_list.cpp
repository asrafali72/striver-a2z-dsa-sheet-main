/*
Problem: Palindrome Linked List

Platform: LeetCode

Short Explanation:
- Find middle using slow & fast pointers.
- Reverse second half (by creating new reversed list).
- Compare first half and reversed second half.
- If all values match → palindrome.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half (new list)
        ListNode* l2 = NULL;
        ListNode* slow1 = slow;

        while (slow1 != NULL) {
            ListNode* p = new ListNode(slow1->val);
            p->next = l2;
            l2 = p;
            slow1 = slow1->next;
        }

        // Compare both halves
        while (l2) {
            if (head->val != l2->val)
                return false;

            head = head->next;
            l2 = l2->next;
        }

        return true;
    }
};