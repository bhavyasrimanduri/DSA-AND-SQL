class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> arr;
        for(auto &row:grid){
            for(int x:row){
                arr.push_back(x);
            }
        }
        int total=arr.size();
        k %=total;
        reverse(arr.begin(),arr.end());
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        int idx=0;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=arr[idx++];
            }
        }
        return ans;
    }
};