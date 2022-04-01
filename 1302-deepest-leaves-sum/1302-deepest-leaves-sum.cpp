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
        
        return max(left,right) + 1;
    }
    
    void solve(TreeNode* root, int height, int& sum){
        if(!root) return;
        if(height == 0){ //leaf
            sum += root->val;
            return;
        }
        solve(root->left, height - 1,sum);
        solve(root->right, height - 1, sum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = get_height(root);
        int sum = 0;
        solve(root, height - 1, sum);
        return sum;
    }
};