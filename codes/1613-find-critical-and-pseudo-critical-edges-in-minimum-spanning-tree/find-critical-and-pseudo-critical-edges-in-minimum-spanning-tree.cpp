class Solution {
public:

    struct DSU {
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;

            return true;
        }
    };

    // Calculate MST weight.
    // skip = edge that must not be used
    // force = edge that must be used first
    int kruskal(int n, vector<vector<int>>& edges,
                int skip, int force) {

        DSU dsu(n);
        int weight = 0;
        int count = 0;

        // Force this edge first
        if (force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            dsu.unite(u, v);

            weight += w;
            count++;
        }

        // Normal Kruskal
        for (int i = 0; i < edges.size(); i++) {

            if (i == skip || i == force)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                weight += w;
                count++;
            }
        }

        // MST must contain exactly n-1 edges
        if (count != n - 1)
            return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {

        // Add original index
        vector<vector<int>> e;

        for (int i = 0; i < edges.size(); i++) {
            e.push_back({
                edges[i][0],
                edges[i][1],
                edges[i][2],
                i
            });
        }

        // Sort by weight
        sort(e.begin(), e.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<int> critical;
        vector<int> pseudo;

        // Normal MST weight
        int mstWeight = kruskal(n, e, -1, -1);

        for (int i = 0; i < e.size(); i++) {

            int originalIndex = e[i][3];

            // ---------------------------------
            // 1. Check if edge is CRITICAL
            // ---------------------------------

            int withoutEdge = kruskal(n, e, i, -1);

            if (withoutEdge > mstWeight) {
                critical.push_back(originalIndex);
                continue;
            }

            // ---------------------------------
            // 2. Check if edge is PSEUDO-CRITICAL
            // ---------------------------------

            int withEdge = kruskal(n, e, -1, i);

            if (withEdge == mstWeight) {
                pseudo.push_back(originalIndex);
            }
        }

        return {critical, pseudo};
    }
};