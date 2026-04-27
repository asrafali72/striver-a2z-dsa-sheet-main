/*
===========================================================
📌 Problem: Task Scheduler (LeetCode 621)

📝 File: task_scheduler.cpp

🧠 Intuition:
- We need to schedule tasks such that same tasks have at least n gap.
- Greedy idea:
      Always execute the most frequent task first.
- Use Max Heap to always pick the task with highest frequency.

⚙️ Approach:
1. Count frequency of each task (A–Z).
2. Push all frequencies into Max Heap.
3. Process in cycles of size (n + 1):
      - In one cycle, pick up to (n + 1) tasks
      - Decrease their frequency
      - Store remaining in temp
4. Push remaining tasks back into heap.
5. If heap not empty → add idle time (remaining slots in cycle)

⏱️ Time Complexity: O(N log 26) ≈ O(N)
📦 Space Complexity: O(26) ≈ O(1)

===========================================================
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Frequency count
        vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }

        // Step 2: Max Heap
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) pq.push(f);
        }

        int time = 0;

        // Step 3: Process cycles
        while (!pq.empty()) {

            int cycle = n + 1;
            vector<int> temp;

            // Fill one cycle
            while (!pq.empty() && cycle > 0) {

                int curr = pq.top();
                pq.pop();

                time++;
                cycle--;

                if (curr - 1 > 0) {
                    temp.push_back(curr - 1);
                }
            }

            // Push remaining tasks back
            for (int t : temp) {
                pq.push(t);
            }

            // Add idle time if needed
            if (!pq.empty()) {
                time += cycle;
            }
        }

        return time;
    }
};