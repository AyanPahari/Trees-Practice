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
    
    void solve(TreeNode* root, bool& flag, int val){
        if(!root) return;
        if(val != root->val){
            flag = false;
            return;
        }
        solve(root->left, flag, val);
        solve(root->right, flag, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        bool flag = true;
        int val = root->val;
        solve(root, flag, val);
        return flag;
    }
};