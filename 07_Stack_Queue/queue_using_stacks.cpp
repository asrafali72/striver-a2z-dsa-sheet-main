/*
Problem: Implement Queue using Stacks

Platform: LeetCode

Short Explanation:
- Implement queue (FIFO) using stacks (LIFO).
- Use two stacks:
    - Push:
        - Move all elements from s2 → s1
        - Push new element into s1
        - Move everything back to s2
    - Pop / Peek:
        - Operate directly on s2 (front element always on top)

Time Complexity:
- push(): O(n)
- pop(): O(1)
- peek(): O(1)

Space Complexity: O(n)
*/

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {

        // Move all elements to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        // Push new element
        s1.push(x);

        // Move back to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int pop() {
        int val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        return s2.top();
    }

    bool empty() {
        return s2.empty();
    }
};