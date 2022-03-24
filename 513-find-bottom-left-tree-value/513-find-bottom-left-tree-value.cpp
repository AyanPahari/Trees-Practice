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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>ans;
            while(size--){
                TreeNode* u = q.front();
                q.pop();
                ans.push_back(u->val);
                
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            res.push_back(ans);
        }
        return res[res.size()-1][0];
    }
};