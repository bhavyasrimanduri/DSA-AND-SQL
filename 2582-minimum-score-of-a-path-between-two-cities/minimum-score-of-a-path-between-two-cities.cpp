class Solution {
public:
    void DFS(int u,unordered_map<int, vector<pair<int,int>>> &adj,vector<bool> &visited,int &result){
        visited[u]=true;
        for(auto &p:adj[u]){
           int v=p.first;
           int d=p.second;
           result=min(result,d);
           if(!visited[v]){
            DFS(v,adj,visited,result);
           }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<bool> visited(n,false);
        for(auto &vec: roads){
            int u=vec[0];
            int v=vec[1];
            int d=vec[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        int result=INT_MAX;
        DFS(1,adj,visited,result);
        return result;
    }
};