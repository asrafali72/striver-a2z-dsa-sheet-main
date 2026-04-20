/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: LRU Cache (Least Recently Used)

🧠 Intuition:
- We need O(1) get & put.
- Use:
      ✔ Doubly Linked List → maintain order (recent → front)
      ✔ HashMap → direct access to nodes
- Most recently used → front
- Least recently used → back

⚙️ Approach:
1. get(key):
      - If not present → return -1
      - Move node to front (recent)
2. put(key, value):
      - If exists → update + move to front
      - Else:
            • Insert at front
            • If capacity exceeded → remove from back

⏱️ Time Complexity: O(1)
📦 Space Complexity: O(capacity)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class LRUCache {
public:
    list<int> dll; // stores keys
    map<int, pair<list<int>::iterator, int>> m; 
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    // Move key to front (most recently used)
    void makeRecently(int key) {
        dll.erase(m[key].first);
        dll.push_front(key);
        m[key].first = dll.begin();
    }

    int get(int key) {
        if (m.find(key) == m.end()) return -1;

        makeRecently(key);
        return m[key].second;
    }

    void put(int key, int value) {

        if (m.find(key) != m.end()) {
            // Update existing
            m[key].second = value;
            makeRecently(key);
        } 
        else {
            // Insert new
            dll.push_front(key);
            m[key] = {dll.begin(), value};
            capacity--;
        }

        // Remove LRU if capacity exceeded
        if (capacity < 0) {
            int lru = dll.back();
            dll.pop_back();
            m.erase(lru);
            capacity++;
        }
    }
};

/*
Usage:
LRUCache* obj = new LRUCache(capacity);
int val = obj->get(key);
obj->put(key, value);
*/