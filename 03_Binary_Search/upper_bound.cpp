class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int ans=-1,lo=0,hi=arr.size()-1;
        if(arr[hi]<target) return hi+1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(target>=arr[mid]){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans+1;
    }
};
