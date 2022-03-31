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
    
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>output, int sum){
        if(!root) return;
        if(!root->left && !root->right){ //if the current node is a leaf node
            sum += root->val;
            output.push_back(root->val);
            if(sum == targetSum){
                res.push_back(output);
                return;
            }
        }
        sum += root->val;
        output.push_back(root->val);
        solve(root->left, targetSum, res, output, sum);
        solve(root->right, targetSum, res, output, sum);
        sum = 0;
        output.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        if(!root) return res;
        vector<int>output;
        int sum = 0;
        solve(root, targetSum, res, output, sum);
        return res;
    }
};