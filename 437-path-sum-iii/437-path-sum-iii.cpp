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
    
    void find(TreeNode* root, int count, int targetSum, int &counter, long long curr_sum){
        if(!root) return;
        curr_sum += root->val;
        if(targetSum == curr_sum){
            counter++;
        }
        find(root->left, count, targetSum,counter, curr_sum);
        find(root->right, count, targetSum,counter, curr_sum);
    }
    
    void solve(TreeNode* root, int& count, int targetSum){
        if(!root) return;
        
        bool flag = false;
        int counter = 0;
        long long curr_sum = 0;
        find(root,count, targetSum, counter, curr_sum);
        count+=counter;
        
        solve(root->left, count, targetSum);
        solve(root->right, count, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        if(!root) return count;
        solve(root,count, targetSum);
        return count;
    }
};