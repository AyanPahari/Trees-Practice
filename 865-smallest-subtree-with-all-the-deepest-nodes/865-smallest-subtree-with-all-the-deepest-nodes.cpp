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
    
    int get_height(TreeNode* root){
        if(!root) return 0;
        int left = get_height(root->left);
        int right = get_height(root->right);
        
        return 1 + max(left,right);
    }
    
    TreeNode* get_lcs(TreeNode* root, TreeNode* a, TreeNode* b){
        if(!root) return NULL;
        if(root->val == a->val || root->val == b->val) return root;
        TreeNode* left = get_lcs(root->left, a, b);
        TreeNode* right = get_lcs(root->right, a, b);
        if(!right) return left;
        else if(!left) return right;
        else return root;
    }
    
    void get_deepest_leaves(TreeNode* root, int height, vector<TreeNode*>& leaves){
        if(!root) return;
        if(height == 0){
            leaves.push_back(root);
            return;
        }
        get_deepest_leaves(root->left, height-1, leaves);
        get_deepest_leaves(root->right, height-1,leaves);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = get_height(root);
        vector<TreeNode*>leaves;
        get_deepest_leaves(root,height-1, leaves);
        
        TreeNode* ans = NULL;
        if(leaves.size() == 1) return leaves[0];
        ans = get_lcs(root, leaves[0], leaves[1]);
        
        for(int i=2;i<leaves.size();i++){
            ans = get_lcs(root, ans, leaves[i]);
        }
        return ans;
    }
};