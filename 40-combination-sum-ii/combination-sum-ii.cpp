class Solution {
public:
    void findcombin(int indx,int target,vector<int> &candiates,vector<int> &ds,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=indx;i<candiates.size();i++){
            if(i>indx && candiates[i]==candiates[i-1]) continue;
            if(candiates[i]>target) break;
            ds.push_back(candiates[i]);
            findcombin(i+1,target-candiates[i],candiates,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findcombin(0,target,candidates,ds,ans);
        return ans;
    }
};