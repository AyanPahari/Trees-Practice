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
    
    void solve(TreeNode* root, int curr_max, int& count){
        if(!root) return;
        if(root->val >= curr_max){
            curr_max = root->val;
            count++;
        }
        solve(root->left, curr_max, count);
        solve(root->right, curr_max, count);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        int curr_max = INT_MIN;
        solve(root, curr_max, count);
        return count;
    }
};