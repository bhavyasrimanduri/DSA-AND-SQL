class Solution {
public:
    void dfs(int k,vector<vector<int>>& adj,vector<bool>& visited){
        visited[k]=true;
        for(int vis:adj[k]){
            if(!visited[vis]){
                dfs(vis,adj,visited);
            }
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &vec:invocations){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(n,false);
        vector<int> ans;
        dfs(k,adj,visited);
        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            if(!visited[u]&&visited[v]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> anse;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                anse.push_back(i);
            }
        }
        return anse;
    }
};