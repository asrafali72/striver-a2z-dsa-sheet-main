/*
===========================================================
📌 Problem: Kth Largest Element in a Stream (LeetCode 703)

🧠 Intuition:
- Maintain the k-th largest element dynamically.
- Instead of storing all elements:
      keep only k largest elements.
- Use Min Heap of size k:
      smallest element in heap = k-th largest overall.

⚙️ Approach:
1. Use Min Heap (size ≤ k).
2. Constructor:
      - Push all elements into heap
      - If size > k → remove smallest
3. add(val):
      - Push val into heap
      - If size > k → remove smallest
      - Return heap top (k-th largest)

⏱️ Time Complexity:
      Constructor: O(N log K)
      add(): O(log K)

📦 Space Complexity: O(K)

===========================================================
*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int x : nums) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */