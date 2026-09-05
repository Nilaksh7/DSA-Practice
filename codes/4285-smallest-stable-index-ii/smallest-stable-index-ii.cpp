class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suf[i] = minimum element from i to n-1
        vector<int> suf(n);

        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(nums[i], suf[i + 1]);
        }

        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            // max(nums[0..i])
            mx = max(mx, nums[i]);

            // min(nums[i..n-1]) = suf[i]
            if (mx - suf[i] <= k)
                return i;
        }

        return -1;
    }
};