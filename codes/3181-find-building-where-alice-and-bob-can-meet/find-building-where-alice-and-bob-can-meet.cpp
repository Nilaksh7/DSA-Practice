class Solution {
public:
    vector<int> seg;
    int n;

    void build(int node, int l, int r, vector<int>& heights) {
        if (l == r) {
            seg[node] = heights[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid, heights);
        build(2 * node + 2, mid + 1, r, heights);

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    // Find the leftmost index >= ql having height > h
    int findFirst(int node, int l, int r, int ql, int h) {
        // Range is completely before ql
        if (r < ql)
            return -1;

        // No building in this range can satisfy the condition
        if (seg[node] <= h)
            return -1;

        // Leaf
        if (l == r)
            return l;

        int mid = l + (r - l) / 2;

        // Search left first because we need LEFTMOST
        int left = findFirst(2 * node + 1, l, mid, ql, h);

        if (left != -1)
            return left;

        return findFirst(2 * node + 2, mid + 1, r, ql, h);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                         vector<vector<int>>& queries) {
        n = heights.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, heights);

        vector<int> ans;

        for (auto& q : queries) {
            int a = q[0];
            int b = q[1];

            // Make a the smaller index
            if (a > b)
                swap(a, b);

            // Already at the same building
            if (a == b) {
                ans.push_back(a);
                continue;
            }

            // Bob can directly move to Alice's building
            // if Alice's building is taller.
            if (heights[a] < heights[b]) {
                ans.push_back(b);
                continue;
            }

            // Need a building strictly to the right of b
            // that is taller than BOTH buildings.
            int requiredHeight = max(heights[a], heights[b]);

            int idx = findFirst(
                0,
                0,
                n - 1,
                b + 1,
                requiredHeight
            );

            ans.push_back(idx);
        }

        return ans;
    }
};