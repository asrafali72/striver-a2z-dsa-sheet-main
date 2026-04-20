/*
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
📌 Problem: Online Stock Span

🧠 Intuition:
- For each price, find how many consecutive days (including today)
  the price was less than or equal to today’s price.
- Use a monotonic decreasing stack:
      • Store (price, span)
      • Merge spans when popping

⚙️ Approach:
1. Maintain stack of pairs {price, span}.
2. For each new price:
      - Initialize span = 1
      - While stack top <= current price:
            add its span and pop
3. Push {price, span}
4. Return span

⏱️ Time Complexity: O(1) amortized per call
📦 Space Complexity: O(n)

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
*/

class StockSpanner {
public:
    stack<pair<int,int>> st;

    StockSpanner() {}

    int next(int price) {

        int span = 1;

        // Merge spans of smaller/equal prices
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price with span
        st.push({price, span});

        return span;
    }
};

/*
Usage:
StockSpanner* obj = new StockSpanner();
int ans = obj->next(price);
*/