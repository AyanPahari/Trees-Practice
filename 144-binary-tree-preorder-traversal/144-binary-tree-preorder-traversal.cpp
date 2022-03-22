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
    vector<int> preorderTraversal(TreeNode* root) {
        //iterative preorder
        
        vector<int>res;
        if(root == NULL) return res;
        
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            res.push_back(curr->val);
            if(curr->right!=NULL) s.push(curr->right);
            if(curr->left!=NULL) s.push(curr->left);
        }
        return res;
    }
};