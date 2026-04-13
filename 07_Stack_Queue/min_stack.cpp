/*
Problem: Min Stack

Platform: LeetCode

Short Explanation:
- Design a stack that supports:
    - push()
    - pop()
    - top()
    - getMin() → returns minimum element in O(1)
- Use two stacks:
    - st → stores all elements
    - mini → stores minimum at each level
- At every push:
    - Push min(current, previous_min)

Time Complexity:
- push(): O(1)
- pop(): O(1)
- top(): O(1)
- getMin(): O(1)

Space Complexity: O(n)
*/

class MinStack {
public:
    stack<int> st;
    stack<int> mini;

    MinStack() {}

    void push(int val) {

        st.push(val);

        if (!mini.empty()) {
            mini.push(min(mini.top(), val));
        }
        else {
            mini.push(val);
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
            mini.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mini.top();
    }
};