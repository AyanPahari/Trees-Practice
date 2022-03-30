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
    
    void solve(TreeNode* root, vector<string>& res, string output){
        if(!root) return;
        if(!root->left && !root->right){
            output += to_string(root->val);
            res.push_back(output);
            return;
        }
        output = output + to_string(root->val) + "->";
        solve(root->left,res,output);
        solve(root->right,res,output);
        output.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string output;
        solve(root, res, output);
        return res;
    }
};