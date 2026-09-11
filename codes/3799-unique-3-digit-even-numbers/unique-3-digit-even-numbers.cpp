class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            // Must be even
            if (num % 2 != 0)
                continue;

            int x = num;
            int cnt[10] = {};

            // Get frequency of digits in num
            while (x > 0) {
                cnt[x % 10]++;
                x /= 10;
            }

            // Check whether digits has enough copies
            int available[10] = {};
            for (int d : digits)
                available[d]++;

            bool possible = true;

            for (int i = 0; i < 10; i++) {
                if (cnt[i] > available[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};