/*
Problem: Merge Sorted Array
Platform: LeetCode

Approach:
First move the valid elements of nums1 (size m) to the end.
Then use three pointers:
i → nums2 (0 to n-1)
j → shifted part of nums1
k → position to fill in nums1
Merge both arrays in sorted order into nums1.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(n == 0) return;

        int hi = nums1.size() - 1;

        for(int i = m - 1; i >= 0; i--){
            swap(nums1[i], nums1[hi]);
            hi--;
        }

        int i = 0, j = n, k = 0;

        while(i < n && j < nums1.size()){

            if(nums1[j] <= nums2[i]){
                nums1[k] = nums1[j];
                j++;
            }
            else{
                nums1[k] = nums2[i];
                i++;
            }

            k++;
        }

        while(i < n){
            nums1[k] = nums2[i];
            i++;
            k++;
        }
    }
};
