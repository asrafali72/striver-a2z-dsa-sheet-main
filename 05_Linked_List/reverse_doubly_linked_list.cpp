/*
Problem: Reverse a Doubly Linked List (Recursive)

Platform: GeeksforGeeks / Standard DSA

Short Explanation:
- Swap next and prev for each node.
- Move to previous node (after swap).
- When prev becomes NULL → new head found.

Time Complexity: O(n)
Space Complexity: O(n)  // recursion stack
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* reverse(Node* curr) { 

    if(curr == nullptr)
        return nullptr;

    swap(curr->prev, curr->next);

    if(curr->prev == nullptr)
        return curr;

    return reverse(curr->prev);
}

void printList(Node *node) {
    while(node != nullptr){
        cout << node->data;
        if(node->next != nullptr)
            cout << " <-> ";
        node = node->next;
    }
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = reverse(head);
    printList(head);

    return 0;
}