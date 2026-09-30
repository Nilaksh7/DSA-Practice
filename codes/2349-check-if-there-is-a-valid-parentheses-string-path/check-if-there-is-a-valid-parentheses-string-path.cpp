class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Maximum possible balance = path length
        int len = m + n - 1;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        // First character must be '('
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int bal = 0; bal <= len; bal++) {

                    if (!dp[i][j][bal])
                        continue;

                    // Move down
                    if (i + 1 < m) {
                        int newBal = bal +
                            (grid[i + 1][j] == '(' ? 1 : -1);

                        if (newBal >= 0 && newBal <= len)
                            dp[i + 1][j][newBal] = true;
                    }

                    // Move right
                    if (j + 1 < n) {
                        int newBal = bal +
                            (grid[i][j + 1] == '(' ? 1 : -1);

                        if (newBal >= 0 && newBal <= len)
                            dp[i][j + 1][newBal] = true;
                    }
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};