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
    
    bool checker(vector<int>& ans, int ind){
        
        if(ind % 2 == 0){
            for(int i=0;i<ans.size();i++){
                if(ans[i] % 2 == 0) return false;
                if(i+1<ans.size() && ans[i]>=ans[i+1]) return false;
            }
        }
        else{
            for(int i=0;i<ans.size();i++){
                if(ans[i] % 2 != 0) return false;
                if(i+1<ans.size() && ans[i]<=ans[i+1]) return false;
            }
        }
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        int ind = 0;
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
            if(checker(ans,ind) == false) return false;
            ind++;
        }
        return true;
    }
};