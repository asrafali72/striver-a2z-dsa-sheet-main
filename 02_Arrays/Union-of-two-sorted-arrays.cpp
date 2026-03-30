/*
Problem: Union of Two Sorted Arrays
Platform: GeeksforGeeks

Approach:
Use the two-pointer technique since both arrays are sorted.
Start with pointers i and j at the beginning of arrays a and b.
Compare elements from both arrays and insert the smaller element
into the result vector while avoiding duplicates.
Move the corresponding pointer forward.
After one array finishes, add remaining elements from the other
array while still avoiding duplicates.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {

        vector<int> ans;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        if(a[i] <= b[j]){
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }

        while(i < n && j < m){
            int s = ans.size() - 1;

            if(a[i] == ans[s]){
                i++;
                continue;
            }

            if(b[j] == ans[s]){
                j++;
                continue;
            }

            if(a[i] <= b[j]){
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }

        while(i < n){
            int s = ans.size() - 1;

            if(a[i] == ans[s]){
                i++;
            } else {
                ans.push_back(a[i]);
                i++;
            }
        }

        while(j < m){
            int s = ans.size() - 1;

            if(b[j] == ans[s]){
                j++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }

        return ans;
    }
};
