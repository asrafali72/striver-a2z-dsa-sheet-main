class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int ans=0,sum=0;
        unordered_map<int,int>m;
        m[0]=-1;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(m.find(sum)!=m.end()){
                ans=max(ans,i-m[sum]);
            }else{
                m[sum]=i;
            }
        }
        return ans;
    }
};
