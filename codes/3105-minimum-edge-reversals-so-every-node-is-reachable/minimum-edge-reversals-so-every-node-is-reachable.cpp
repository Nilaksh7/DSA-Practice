class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        // For edge u -> v:
        // u -> v costs 0 reversals
        // v -> u costs 1 reversal
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> ans(n, 0);

        // First DFS: calculate answer[0]
        function<void(int, int)> dfs1 = [&](int node, int parent) {
            for (auto &[next, cost] : adj[node]) {
                if (next == parent)
                    continue;

                ans[0] += cost;
                dfs1(next, node);
            }
        };

        dfs1(0, -1);

        // Second DFS: reroot the answer
        function<void(int, int)> dfs2 = [&](int node, int parent) {
            for (auto &[next, cost] : adj[node]) {
                if (next == parent)
                    continue;

                if (cost == 0) {
                    // Original edge: node -> next
                    // Moving root to next makes it wrong
                    ans[next] = ans[node] + 1;
                } else {
                    // Original edge: next -> node
                    // Moving root to next makes it correct
                    ans[next] = ans[node] - 1;
                }

                dfs2(next, node);
            }
        };

        dfs2(0, -1);

        return ans;
    }
};