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
    
    void solve(TreeNode* root, int targetSum, int sum, bool& flag){
        if(!root) return;
        if(!root->left && !root->right){
            sum += root->val;
            if(sum == targetSum){
                flag = true;
                return;
            }
        }
        sum += root->val;
        solve(root->left, targetSum, sum, flag);
        solve(root->right, targetSum, sum, flag);
        sum = 0;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int sum = 0;
        bool flag = false;
        solve(root,targetSum, sum, flag);
        return flag;
    }
};