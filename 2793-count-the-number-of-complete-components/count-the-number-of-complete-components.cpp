class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visit,int &nodes,int &edgecnt){
        visit[node]=1;
        nodes++;
        edgecnt +=adj[node].size();
        for(int s:adj[node]){
            if(!visit[s]){
                dfs(s,adj,visit,nodes,edgecnt);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> visit(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                int nodes=0;
                int edgecnt=0;
                dfs(i,adj,visit,nodes,edgecnt);
                edgecnt /= 2;
                if(edgecnt==nodes*(nodes-1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};