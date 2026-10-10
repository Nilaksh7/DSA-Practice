class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);

        long long total = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (total <= k)
            return 0;

        vector<long long> freq(maxi + 1, 0);

        for (int d : diff)
            freq[d]++;

        for (int d = maxi; d > 0 && k > 0; d--) {
            if (freq[d] == 0)
                continue;

            long long count = freq[d];
            long long nextCount = freq[d - 1];
            long long need = count;

            if (k >= need) {
                freq[d - 1] += count;
                freq[d] = 0;
                k -= need;
            } else {
                long long full = k / count;
                long long rem = k % count;

                freq[d] -= rem;
                freq[d - 1] += rem;

                if (full > 0) {
                    freq[d - full] += count - rem;
                    freq[d] -= count - rem;
                }

                k = 0;
            }
        }

        long long ans = 0;

        for (int d = 1; d <= maxi; d++)
            ans += 1LL * d * d * freq[d];

        return ans;
    }
};