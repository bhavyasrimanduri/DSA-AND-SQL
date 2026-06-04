class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a=-1,b;
        long long sum = 0,expectedsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                if(s.find(grid[i][j])!= s.end()){
                    a=grid[i][j];
                }
                s.insert(grid[i][j]);
            }        
        }
        expectedsum =1LL * (n*n) * ((n*n) +1) / 2;
        b = expectedsum + a - sum;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};