class Solution {
public:

    // cnt[d][i] = number of prime factors 2, 3, 5, 7 in digit d
    vector<vector<int>> cnt = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    // Minimum digits needed to provide 'a' factors of 2 and 'b' factors of 3
    int min23(int a, int b) {
        int ans = INT_MAX;

        // z = number of 6's
        for (int z = 0; z <= min(a, b); z++) {
            int r2 = a - z;
            int r3 = b - z;

            int digits = z;
            digits += (r2 + 2) / 3; // 8 gives maximum 3 factors of 2
            digits += (r3 + 1) / 2; // 9 gives maximum 2 factors of 3

            ans = min(ans, digits);
        }

        return ans;
    }

    int minDigits(vector<int>& req) {
        return min23(req[0], req[1])
             + req[2]       // each 5 gives one 5
             + req[3];      // each 7 gives one 7
    }

    bool possible(vector<int>& req, int slots) {
        for (int x : req) {
            if (x < 0) return false;
        }
        return minDigits(req) <= slots;
    }

    // Build smallest possible string of length len
    string build(vector<int> req, int len) {
        string ans = "";

        for (int pos = 0; pos < len; pos++) {
            int remaining = len - pos - 1;

            // Try digits from smallest to largest
            for (int d = 1; d <= 9; d++) {
                vector<int> newReq(4);
                for (int p = 0; p < 4; p++) {
                    newReq[p] = max(0, req[p] - cnt[d][p]);
                }

                if (possible(newReq, remaining)) {
                    ans += char('0' + d);
                    req = newReq;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        // ------------------------------------------------
        // Step 1: Factorize t
        // ------------------------------------------------
        vector<int> req(4, 0);
        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                req[i]++;
                t /= primes[i];
            }
        }

        if (t != 1) return "-1";


        // ------------------------------------------------
        // Step 2: Check whether num itself works
        // ------------------------------------------------
        bool zero = false;
        vector<int> have(4, 0);

        for (char ch : num) {
            int d = ch - '0';
            if (d == 0) {
                zero = true;
                continue;
            }
            for (int p = 0; p < 4; p++) {
                have[p] += cnt[d][p];
            }
        }

        if (!zero) {
            bool ok = true;
            for (int p = 0; p < 4; p++) {
                if (have[p] < req[p]) ok = false;
            }
            if (ok) return num;
        }


        // ------------------------------------------------
        // Step 3: Try same length
        // ------------------------------------------------
        int n = num.size();

        // Find the index of the first '0' if any
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<vector<int>> prefix(n + 1, vector<int>(4, 0));
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            for (int p = 0; p < 4; p++) {
                prefix[i + 1][p] = prefix[i][p] + cnt[d][p];
            }
        }

        // Only start from positions <= first_zero
        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            int original = num[i] - '0';

            // Try making this digit larger
            for (int d = original + 1; d <= 9; d++) {
                vector<int> remainingReq(4);
                for (int p = 0; p < 4; p++) {
                    int already = prefix[i][p] + cnt[d][p];
                    remainingReq[p] = max(0, req[p] - already);
                }

                int remainingSlots = n - i - 1;

                if (possible(remainingReq, remainingSlots)) {
                    string ans = num.substr(0, i);
                    ans += char('0' + d);
                    ans += build(remainingReq, remainingSlots);
                    return ans;
                }
            }
        }


        // ------------------------------------------------
        // Step 4: Same length impossible
        // ------------------------------------------------
        int need = minDigits(req);
        int len = max(n + 1, need);

        return build(req, len);
    }
};