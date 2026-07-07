class Solution {
public:
    bool isPalindrome(string &s,int strt,int end){
         while(strt<=end){
            if(s[strt++]!=s[end--]){
                return false;
            }
         }
         return true;
    }
    void func(int indx,string &s,vector<string> &ds,vector<vector<string>> &ans){
        if(indx==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=indx;i<s.size();i++){
            if (isPalindrome(s, indx, i)) {
                ds.push_back(s.substr(indx, i - indx + 1));
                func(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        func(0,s,ds,ans);
        return ans;
    }
};