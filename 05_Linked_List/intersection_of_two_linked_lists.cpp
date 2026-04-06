/*
Problem: Intersection of Two Linked Lists

Platform: LeetCode

Short Explanation:
- Count lengths of both lists.
- Move pointer of longer list ahead by difference.
- Traverse both lists together.
- First common node is the intersection.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

        int count1 = 0, count2 = 0;
        ListNode* t1 = head1;
        ListNode* t2 = head2;

        // Count length of first list
        while (t1 != NULL) {
            count1++;
            t1 = t1->next;
        }

        // Count length of second list
        while (t2 != NULL) {
            count2++;
            t2 = t2->next;
        }

        // Align both lists
        if (count1 < count2) {
            count2 -= count1;
            while (count2--) {
                head2 = head2->next;
            }
        } else {
            count1 -= count2;
            while (count1--) {
                head1 = head1->next;
            }
        }

        // Find intersection point
        while (head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }

        return head1; // intersection node (or NULL)
    }
};