/*
Problem: Add Two Numbers

Platform: LeetCode

Short Explanation:
- Traverse both lists simultaneously.
- Add corresponding digits along with carry.
- Create new node with (sum % 10).
- Update carry (sum / 10).
- Continue for remaining nodes.
- Add final carry if present.

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = new ListNode(0);
        ListNode* ans1 = ans;
        int a = 0; // carry

        // Traverse both lists
        while (l1 != NULL && l2 != NULL) {
            int b = l1->val + l2->val + a;
            ListNode* temp = new ListNode(b % 10);

            ans->next = temp;
            ans = temp;

            a = b / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        // Remaining nodes of l1
        while (l1 != NULL) {
            int b = l1->val + a;
            ListNode* temp = new ListNode(b % 10);

            ans->next = temp;
            ans = temp;

            a = b / 10;
            l1 = l1->next;
        }

        // Remaining nodes of l2
        while (l2 != NULL) {
            int b = l2->val + a;
            ListNode* temp = new ListNode(b % 10);

            ans->next = temp;
            ans = temp;

            a = b / 10;
            l2 = l2->next;
        }

        // If carry remains
        if (a > 0)
            ans->next = new ListNode(a);

        return ans1->next;
    }
};