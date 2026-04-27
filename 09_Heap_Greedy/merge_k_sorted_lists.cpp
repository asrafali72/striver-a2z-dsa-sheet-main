/*
===========================================================
📌 Problem: Merge K Sorted Lists (LeetCode 23)

📝 File: merge_k_sorted_lists.cpp

🧠 Intuition:
- We have k sorted linked lists.
- Goal: Merge them into one sorted list.
- Brute force → collect + sort → inefficient.
- Optimal idea:
      Always pick the smallest current node among k lists.
- Use Min Heap (Priority Queue) to efficiently get minimum.

⚙️ Approach:
1. Use Min Heap storing:
      (node value, node pointer)
2. Push head of all non-empty lists into heap.
3. Create dummy node for result list.
4. While heap is not empty:
      - Extract smallest node
      - Attach it to result
      - If extracted node has next → push into heap
5. Return dummy.next

⏱️ Time Complexity: O(N log K)
      N = total nodes, K = number of lists

📦 Space Complexity: O(K)
      Heap stores at most K elements

===========================================================
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap: (value, node)
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Push all list heads into heap
        for (auto node : lists) {
            if (node) {
                pq.push({node->val, node});
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Process heap
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ListNode* curr = it.second;

            tail->next = curr;
            tail = tail->next;

            // Push next node of current list
            if (curr->next) {
                pq.push({curr->next->val, curr->next});
            }
        }

        return dummy.next;
    }
};