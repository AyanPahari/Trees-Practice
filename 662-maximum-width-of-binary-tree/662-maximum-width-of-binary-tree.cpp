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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root, 0});
        int ans = INT_MIN;
        
        while(!q.empty()){
            int size = q.size();
            vector<unsigned long long>res;
            while(size--){
                TreeNode* u = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                res.push_back(index);
                
                if(u->left) q.push({u->left, 2*index + 1});
                if(u->right) q.push({u->right, 2*index + 2});
            }
            int temp = res.back() - res[0] + 1;
            ans = max(ans, temp);
        }
        return ans;
    }
};