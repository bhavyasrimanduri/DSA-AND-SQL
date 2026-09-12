class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    Node better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;

        if (lexicographical_compare(
                a.indices.begin(), a.indices.end(),
                b.indices.begin(), b.indices.end()))
            return a;

        return b;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[3] < b[3];
             });

        vector<int> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = intervals[i][0];

        vector<array<Node, 5>> dp(n + 1);

        for (int k = 0; k <= 4; k++)
            dp[n][k] = {0, {}};

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                Node skip = dp[i + 1][k];

                int next = upper_bound(
                    starts.begin(),
                    starts.end(),
                    intervals[i][1]
                ) - starts.begin();

                Node take = dp[next][k - 1];

                take.score += intervals[i][2];
                take.indices.push_back(intervals[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(skip, take);
            }

            dp[i][0] = {0, {}};
        }

        return dp[0][4].indices;
        
    }
};