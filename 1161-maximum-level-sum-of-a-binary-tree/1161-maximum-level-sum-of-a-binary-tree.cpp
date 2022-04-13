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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>output;
            while(size--){
                TreeNode* u = q.front();
                q.pop();
                output.push_back(u->val);
                
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            res.push_back(output);
        }
        int index = 1;
        int maxi = INT_MIN;
        for(int i=0;i<res.size();i++){
            int sum = 0;
            for(int j=0;j<res[i].size();j++){
                sum += res[i][j];
            }
            if(sum>maxi){
                maxi = sum;
                index = i;
            }
        }
        return index + 1;
    }
};