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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Here, if node to be deleted,say d, has 2 children,say lc,rc, then we join parent node to lc and join the right children to rightmost node of lc subtree;
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);

        TreeNode* curr=root;
        while(curr!=NULL){

            if(curr->val > key){//key is in left

                if(curr->left!=NULL && curr->left->val==key){//i.e. curr->left is the node to be deleted
                    curr->left=helper(curr->left);//updates curr->left with new curr->left
                    break;
                }
                else{
                    curr=curr->left;
                }
            }
            else{//curr->val < key.....key is in right

                if(curr->right!=NULL && curr->right->val==key){//i.e. curr->right is the node to be deleted
                    curr->right=helper(curr->right);//updates curr->right with new curr->right
                    break;
                }
                else{
                    curr=curr->right;
                }
            }
        }
        return root;

    }

    TreeNode* helper(TreeNode* node){//node is element to be deleted and this helper() func. deletes this node and return the new node in place of this node by making required changes in structure of BST
        if(node->left==NULL){
            return node->right;
        }
        else if(node->right==NULL){
            return node->left;
        }
        else{//both children exist
            TreeNode* rightChild = node->right;
            TreeNode* temp=node->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=rightChild;
            return node->left;
        }
    }
};