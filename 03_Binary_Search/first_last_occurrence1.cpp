class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        vector<int>v(2,-1);
        int ans=-1;
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x){
               ans=mid;
               lo=mid+1; 
            }
            else if(arr[mid]<x){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        v[1]=ans;
        ans=-1;
        lo=0;
        hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x){
                ans=mid;
                hi=mid-1;
            }
            else if(arr[mid]>x){
              hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        v[0]=ans;
        return v;
    }
};
