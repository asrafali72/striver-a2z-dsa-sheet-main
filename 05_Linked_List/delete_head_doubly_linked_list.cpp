/*
Problem: Delete Head of Doubly Linked List

Platform: GeeksforGeeks

Short Explanation:
- Move head to next node.
- Set new head's prev to NULL.
- Disconnect old head.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    Node* deleteHead(Node* head) {

        if(head == NULL) return NULL;

        Node* temp = head;
        head = head->next;

        if(head != NULL)
            head->prev = NULL;

        temp->next = NULL;

        return head;
    }
};