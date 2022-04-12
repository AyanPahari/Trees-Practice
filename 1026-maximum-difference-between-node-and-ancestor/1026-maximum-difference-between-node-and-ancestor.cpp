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
    
    void get_path(TreeNode* root, vector<int>output, vector<vector<int>>& res){
        if(!root) return;
        if(!root->left && !root->right){ //leaf node
            output.push_back(root->val);
            res.push_back(output);
            return;
        }
        output.push_back(root->val);
        get_path(root->left, output, res);
        get_path(root->right, output, res);
        output.pop_back();
    }
    
    int maxAncestorDiff(TreeNode* root) {
        // get all the paths from the root to the leaf, and for each path get the abs difference of the highest and the lowest value. Return the maximum out of them.
        vector<int>output;
        vector<vector<int>>res;
        get_path(root, output, res);
        int ans = 0;
        for(auto it:res){
            ans = max(ans, abs(*max_element(it.begin(),it.end()) - *min_element(it.begin(),it.end())));
        }
        return ans;
    }
};