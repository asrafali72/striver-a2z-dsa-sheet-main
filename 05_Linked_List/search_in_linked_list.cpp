/*
Problem: Search in Linked List

Platform: GeeksforGeeks

Short Explanation:
- Traverse the linked list.
- Compare each node's data with key.
- If found → return true.
- Else → return false.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {

        while(head != NULL){
            if(head->data == key){
                return true;
            }
            head = head->next;
        }

        return false;
    }
};