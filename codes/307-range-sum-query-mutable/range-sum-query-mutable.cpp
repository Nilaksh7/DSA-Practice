class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        build(0, 0, n - 1, nums);
    }

    void build(int node, int start, int end, vector<int>& nums) {
        if (start == end) {
            seg[node] = nums[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node + 1, start, mid, nums);
        build(2 * node + 2, mid + 1, end, nums);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            seg[node] = val;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            updateTree(2 * node + 1, start, mid, index, val);
        } else {
            updateTree(2 * node + 2, mid + 1, end, index, val);
        }

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

    int query(int node, int start, int end, int left, int right) {
        // Completely outside range
        if (right < start || end < left)
            return 0;

        // Completely inside range
        if (left <= start && end <= right)
            return seg[node];

        int mid = start + (end - start) / 2;

        int leftSum = query(2 * node + 1, start, mid, left, right);
        int rightSum = query(2 * node + 2, mid + 1, end, left, right);

        return leftSum + rightSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */