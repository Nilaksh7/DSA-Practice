class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MAXX = 1024;

        vector<vector<bool>> dp(n, vector<bool>(MAXX, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> curr(MAXX, false);

                if (i == 0 && j == 0) {
                    curr[grid[i][j]] = true;
                } else {
                    for (int x = 0; x < MAXX; x++) {
                        if (i > 0 && dp[j][x]) {
                            curr[x ^ grid[i][j]] = true;
                        }

                        if (j > 0 && dp[j - 1][x]) {
                            curr[x ^ grid[i][j]] = true;
                        }
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < MAXX; x++) {
            if (dp[n - 1][x]) return x;
        }

        return 0;
    }
};