class Solution {
public:
    const int MOD = 1e9 + 7;

    int dp[205][205][205];

    int solve(int idx, int g1, int g2, vector<int>& nums) {

        if (idx == nums.size()) {
            return (g1 == g2 && g1 != 0);
        }

        if (dp[idx][g1][g2] != -1)
            return dp[idx][g1][g2];

        long long ans = 0;
        ans += solve(idx + 1, g1, g2, nums);

        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans += solve(idx + 1, ng1, g2, nums);

        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans += solve(idx + 1, g1, ng2, nums);

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, nums);
    }
};