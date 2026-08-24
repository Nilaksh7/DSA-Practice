class Solution {
public:
    long long count(long long prefix, long long n) {
        long long next = prefix + 1;
        long long cnt = 0;

        while (prefix <= n) {
            cnt += min(n + 1, next) - prefix;

            prefix *= 10;
            next *= 10;
        }

        return cnt;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;

        // We are already at the first number
        k--;

        while (k > 0) {

            // Count how many numbers are under curr
            long long steps = count(curr, n);

            if (steps <= k) {
                // Skip this entire prefix
                curr++;
                k -= steps;
            }
            else {
                // Go deeper into this prefix
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};