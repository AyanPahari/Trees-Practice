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
    
    unsigned long long sum,index;
    int count;
    
    void solve(TreeNode* root, unsigned long long index){
        if(!root) return;
        count++;
        sum += index;
        solve(root->left, 2*index);
        solve(root->right, 2*index + 1);
    }
    
    bool isCompleteTree(TreeNode* root) {
        solve(root, 1);
        return count*(count+1)/2 == sum;
    }
};