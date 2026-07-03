class Solution {
public:
    bool check(int x,
               vector<vector<pair<int,int>>> &adj,
               vector<int> &topo,
               vector<bool> &online,
               long long k) {

        int n = online.size();
        vector<long long> dp(n, LLONG_MAX);
        dp[0] = 0;

        for (int u : topo) {
            if (dp[u] == LLONG_MAX) continue;

            for (auto &[v, w] : adj[u]) {
                if (w < x) continue;
                if (v != n - 1 && !online[v]) continue;

                dp[v] = min(dp[v], dp[u] + w);
            }
        }

        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        int mx = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            mx = max(mx, e[2]);
        }

        // Topological Sort
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        int lo = 0, hi = mx;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, adj, topo, online, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};