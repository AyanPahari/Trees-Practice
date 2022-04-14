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
    
    void get_min_height(TreeNode* root, int& min_height, int height){
        if(!root) return;
        if(!root->left && !root->right){ //leaf node
            min_height = min(min_height, height);
            return;
        }
        get_min_height(root->left, min_height, height+1);
        get_min_height(root->right, min_height, height+1);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int min_height = INT_MAX;
        get_min_height(root, min_height, 0);
        return min_height + 1;
    }
};