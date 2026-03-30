class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-3; i++){
            if(0<i && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int lo=j+1,hi=nums.size()-1;
                while(lo<hi){
                    long long sum=(long long)nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(sum==target){
                     ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                     while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                     while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                     lo++;
                     hi--;
                    }else if(sum<target){
                     lo++;
                    }else{
                     hi--;  
                    }
                }
            }
        }
        return ans; 
    }
};
