/*
Problem: Reverse Nodes in k-Group

Platform: LeetCode

Short Explanation:
- Store all node values in a vector.
- Reverse every group of size k in the vector.
- Update linked list values using modified vector.
- Structure of list remains same, only values change.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<int> v;
        ListNode* temp = head;

        // Store values in vector
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Reverse every k-group
        for (int i = 0; i < v.size() - k + 1; i += k) {
            int lo = i, hi = i + k - 1;
            while (lo < hi) {
                swap(v[lo], v[hi]);
                lo++;
                hi--;
            }
        }

        // Update linked list values
        temp = head;
        int i = 0;

        while (temp != NULL) {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};