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
    
    void checker(TreeNode* root, int &sum){
        if(root->left!=NULL){
            if(root->left->left!=NULL) sum += root->left->left->val;
            if(root->left->right!=NULL) sum += root->left->right->val;
        }
        if(root->right!=NULL){
            if(root->right->left!=NULL) sum += root->right->left->val;
            if(root->right->right!=NULL) sum += root->right->right->val;
        }
    }
    
    void dfs(TreeNode* root, int &sum){
        if(root == NULL) return;
        if(root->val % 2 == 0) checker(root,sum);
        dfs(root->left,sum);
        dfs(root->right,sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        dfs(root,sum);
        return sum;
    }
};