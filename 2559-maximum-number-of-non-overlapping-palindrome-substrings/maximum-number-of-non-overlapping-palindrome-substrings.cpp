class Solution {
public:
    bool palindrome(string &s,int start, int end){
        int i=start;
        int j=end;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
          int n = s.size();

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            
            dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {
                
                if (i - j >= k && palindrome(s, j, i - 1)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};