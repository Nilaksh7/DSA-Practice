class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    // Return true if b is lexicographically smaller than a
    bool smaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(
            b.begin(), b.end(),
            a.begin(), a.end()
        );
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by start time
        sort(a.begin(), a.end());

        // next[i] = first interval whose start > current end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1;
            int hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        // dp[i][k]
        // Best answer from i onward using at most k intervals.
        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        // dp[n][k] = score 0, empty vector
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: skip this interval
                Node best = dp[i + 1][k];

                // Option 2: take this interval
                Node take = dp[nxt[i]][k - 1];

                take.score += a[i][2];
                take.ids.push_back((int)a[i][3]);

                sort(take.ids.begin(), take.ids.end());

                // Compare
                if (take.score > best.score) {
                    best = take;
                }
                else if (take.score == best.score) {
                    if (smaller(best.ids, take.ids)) {
                        best = take;
                    }
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].ids;
    }
};