/*
===========================================================
📌 Problem: Find Median from Data Stream (LeetCode 295)

🧠 Intuition:
- We need to maintain median dynamically.
- Split numbers into two halves:
      1. Max Heap (left side)  → smaller half
      2. Min Heap (right side) → larger half
- Balance both heaps such that:
      size difference ≤ 1

⚙️ Approach:
1. Add Number:
      - If number ≤ maxHeap.top → push into maxHeap
      - Else → push into minHeap
2. Balance Heaps:
      - If maxHeap size > minHeap size + 1 → move top to minHeap
      - If minHeap size > maxHeap size → move top to maxHeap
3. Find Median:
      - If sizes unequal → top of maxHeap
      - If equal → average of both tops

⏱️ Time Complexity:
      addNum(): O(log N)
      findMedian(): O(1)

📦 Space Complexity: O(N)

===========================================================
*/

class MedianFinder {
public:
    // Max Heap (left half)
    priority_queue<int> maxHeap;

    // Min Heap (right half)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {

        // Step 1: Insert
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Step 2: Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        // Step 3: Get median
        if (maxHeap.size() > minHeap.size()) {
            return (double)maxHeap.top();
        }

        return (double)(maxHeap.top() + minHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */