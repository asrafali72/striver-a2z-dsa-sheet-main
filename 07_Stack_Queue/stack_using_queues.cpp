
/*
Problem: Implement Stack using Queues

Platform: LeetCode

Short Explanation:
- Implement stack (LIFO) using queues (FIFO).
- Use two queues:
    - Push:
        - Insert element into empty queue.
        - Move all elements from other queue to maintain order.
    - Pop:
        - Remove from front of non-empty queue.
    - Top:
        - Return front of non-empty queue.
- Always keep newest element at front.

Time Complexity:
- push(): O(n)
- pop(): O(1)
- top(): O(1)

Space Complexity: O(n)
*/

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {}

    void push(int x) {

        // Push into empty queue
        if (q1.empty()) {
            q1.push(x);

            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);

            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop() {

        if (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            return val;
        }
        else {
            int val = q2.front();
            q2.pop();
            return val;
        }
    }

    int top() {

        if (!q1.empty()) return q1.front();
        return q2.front();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};