class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 0;
        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long newDp = (2 * dp + 1 - last[idx] + MOD) % MOD;

            last[idx] = (dp + 1) % MOD;

            dp = newDp;
        }

        return dp;
    }
};