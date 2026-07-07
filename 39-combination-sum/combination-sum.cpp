class Solution {
public: 
    void findcombin(int indx,int target,vector<int> &candiates,vector<int> &ds,vector<vector<int>> &ans){
        if(indx==candiates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candiates[indx]<=target){
            ds.push_back(candiates[indx]);
            findcombin(indx,target-candiates[indx],candiates,ds,ans);
            ds.pop_back();
        }
        findcombin(indx+1,target,candiates,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int> ds;
         vector<vector<int>> ans;
         findcombin(0,target,candidates,ds,ans);
         return ans;
    }
};