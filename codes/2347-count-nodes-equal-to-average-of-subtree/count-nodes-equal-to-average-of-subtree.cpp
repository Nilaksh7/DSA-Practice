class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int sum = l.first + r.first + root->val;
        int cnt = l.second + r.second + 1;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};