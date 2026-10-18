class Solution {
private:
    static const int MOD = 1e9 + 7;

    vector<vector<long long>> comb;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;

        // First element is the root
        int root = nums[0];

        // Divide elements into left and right subtrees
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int L = left.size();

        // Number of ways to interleave left and right elements
        long long ways = comb[n - 1][L];

        // Multiply by the number of valid reorderings of each subtree
        ways = (ways * solve(left)) % MOD;
        ways = (ways * solve(right)) % MOD;

        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Precompute binomial coefficients using Pascal's triangle
        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Subtract one to exclude the original ordering
        return (solve(nums) - 1 + MOD) % MOD;
    }
};