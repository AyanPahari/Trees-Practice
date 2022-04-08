/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void get_relation(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent){
        //child --> parent
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* u = q.front();
            q.pop();
            
            if(u->left){
                parent[u->left] = u;
                q.push(u->left);
            }
            if(u->right){
                parent[u->right] = u;
                q.push(u->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        get_relation(root, parent);
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool>vis;
        vis[target] = true;
        int dist = 0;
        vector<int>res;
        
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            while(size--){
                TreeNode* u = q.front();
                q.pop();
            
                if(parent[u] && !vis[parent[u]]){
                    q.push(parent[u]);
                    vis[parent[u]] = true;
                }
                if(u->left && !vis[u->left]){
                    q.push(u->left);
                    vis[u->left] = true;
                }
                if(u->right && !vis[u->right]){
                    q.push(u->right);
                    vis[u->right] = true;
                    }
                }
            }
        while(!q.empty()){
            TreeNode* v = q.front();
            q.pop();
            res.push_back(v->val);
        }
        return res;
    }
};