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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>ans;
            while(size--){
                TreeNode* u = q.front();
                q.pop();
                ans.push_back(u->val);
                
                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
            }
            res.push_back(ans);
        }
        for(int i=0;i<res.size();i++){
            if(i % 2 != 0) reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};