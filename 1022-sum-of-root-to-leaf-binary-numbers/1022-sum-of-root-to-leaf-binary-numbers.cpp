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
    
    int compute_sum(vector<int>res){
        int sum = 0;
        for(int i=0;i<res.size();i++){
            sum += pow(2,res.size() - i - 1)*res[i];
        }
        return sum;
    }
    
    void solve(TreeNode* root, vector<int>res, int& sum){
        if(!root) return;
        if(!root->left && !root->right){ //leaf node
            res.push_back(root->val);
            sum += compute_sum(res);
            return;
        }
        res.push_back(root->val);
        solve(root->left, res, sum);
        solve(root->right, res, sum);
        res.pop_back();
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<int>res;
        int sum = 0;
        solve(root,res,sum);
        return sum;
    }
};