class Solution {
public:
    vector<int> parent,sz;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(sz[x]<sz[y]){
            swap(sz[x],sz[y]);
        }
        parent[y]=x;
        sz[x] += sz[y];
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &e:edges){
            unite(e[0],e[1]);
        }
        unordered_map<int,int> vertices;
        unordered_map<int,int> edgecnt;
        for(int i=0;i<n;i++){
            vertices[find(i)]++;
        }
        for(auto &e:edges){
            edgecnt[find(e[0])]++;
        }
        int ans=0;
        for(auto &it:vertices){
            int root=it.first;
            int v=it.second;
            int e=edgecnt[root];
            if(e==v*(v-1)/2){
                ans++;
            }
        }
        return ans;
    }
};