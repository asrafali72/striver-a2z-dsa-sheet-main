class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
       vector<vector<int>>ans;
       sort(inte.begin(),inte.end());
       int lo=inte[0][0],hi=inte[0][1];
       for(int i=0; i<inte.size(); i++){
        int j=inte[i][0],k=inte[i][1];
        if(j<=hi){
            hi=max(k,hi);
        }else{
            ans.push_back({lo,hi});
            lo=j;
            hi=k;
        }
       } 
       ans.push_back({lo,hi});
       return ans;
    }
};
