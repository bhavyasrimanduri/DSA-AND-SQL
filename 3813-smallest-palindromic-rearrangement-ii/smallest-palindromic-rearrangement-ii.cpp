class Solution {
public:
    const long long LIM = 1000000;

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long res = 1;
        int rem = total;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] == 0) continue;

            int k = cnt[c];
            long long cur = 1;

            for (int i = 1; i <= k; i++) {
                cur = cur * (rem - k + i) / i;
                if (cur > LIM) cur = LIM;
            }

            res *= cur;
            if (res > LIM) res = LIM;

            rem -= k;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        int len = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        string left;

        while ((int)left.size() < len) {
            for (int i = 0; i < 26; i++) {
                if (half[i] == 0)
                    continue;

                half[i]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + i));
                    break;
                } else {
                    k -= ways;
                    half[i]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + mid + right;

        return left + right;
    }
};