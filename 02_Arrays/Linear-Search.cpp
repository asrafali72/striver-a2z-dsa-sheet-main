/*
Problem: Linear Search using Recursion
Platform: GeeksforGeeks

Approach:
Use recursion to traverse the array. Start from index 0 and check
whether the current element equals x. If found, return the index.
Otherwise, recursively check the next index. If the end of the array
is reached, return -1.

Time Complexity: O(n)
Space Complexity: O(n) (due to recursion stack)
*/

class Solution {
public:
    int f(vector<int> &arr, int i, int s, int x){
        if(i == s)
            return -1;

        if(arr[i] == x)
            return i;

        return f(arr, i + 1, s, x);
    }

    int search(vector<int>& arr, int x) {
        int s = arr.size();
        return f(arr, 0, s, x);
    }
};
