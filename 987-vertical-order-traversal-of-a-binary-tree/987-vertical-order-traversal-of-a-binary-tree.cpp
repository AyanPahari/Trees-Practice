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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;    
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;  
        q.push({root, 0}); 
        
        while(!q.empty()){
            multiset<pair<int,int>> temp; 
            int n = q.size();
            
            while(n--){
                TreeNode *curr = q.front().first;
                int h = q.front().second;
                temp.insert({h, curr->val});   
                q.pop();
                
                if(curr->left)
                    q.push({curr->left, h-1}); 

                if(curr->right)
                    q.push({curr->right, h+1}); 
            }
            for(auto it: temp)
                mp[it.first].push_back(it.second); 
        }
        for(auto it: mp)
            ans.push_back(it.second); 
        
        return ans;
    }
};