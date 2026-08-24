/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create nodes if they don't exist
            if (!nodes.count(parent))
                nodes[parent] = new TreeNode(parent);

            if (!nodes.count(child))
                nodes[child] = new TreeNode(child);

            // Connect parent and child
            if (isLeft == 1)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];

            // Child cannot be the root
            children.insert(child);
        }

        // The root is the node that never appeared as a child
        for (auto &[value, node] : nodes) {
            if (!children.count(value))
                return node;
        }

        return nullptr;
    }
};