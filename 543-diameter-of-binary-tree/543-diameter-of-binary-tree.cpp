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
    
    int solve(TreeNode* root, int& maxi){
        if(!root) return 0;
        int L = solve(root->left, maxi);
        int R = solve(root->right, maxi);
        
        maxi = max(maxi,L+R+1);
        return 1 + max(L,R);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root,maxi);
        return maxi - 1;
    }
};