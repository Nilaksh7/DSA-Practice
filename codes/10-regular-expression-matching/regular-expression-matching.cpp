class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j) {
        // Pattern completely finished
        if (j == m)
            return i == n;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Does current character match?
        bool firstMatch = (i < n && 
                           (s[i] == p[j] || p[j] == '.'));

        // If next character is '*'
        if (j + 1 < m && p[j + 1] == '*') {

            // Option 1: '*' matches zero characters
            bool zero = solve(s, p, i, j + 2);

            // Option 2: '*' matches current character
            bool many = firstMatch && solve(s, p, i + 1, j);

            return dp[i][j] = zero || many;
        }

        // Normal character or '.'
        if (firstMatch)
            return dp[i][j] = solve(s, p, i + 1, j + 1);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(s, p, 0, 0);
    }
};