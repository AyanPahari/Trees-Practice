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
    
    void solve(TreeNode* root, vector<vector<int>>& res, vector<int>output){
        if(!root) return;
        if(!root->left && !root->right){ //leaf node
            output.push_back(root->val);
            res.push_back(output);
            return;
        }
        output.push_back(root->val);
        solve(root->left, res, output);
        solve(root->right, res, output);
        output.pop_back();
    }
    
    int sumNumbers(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>output;
        solve(root,res,output);
        int sum = 0;
        for(int i=0;i<res.size();i++){
            int temp = 0;
            for(int j=0;j<res[i].size();j++){
                temp += pow(10,res[i].size()-j-1)*res[i][j];
            }
            sum += temp;
        }
        return sum;
    }
};