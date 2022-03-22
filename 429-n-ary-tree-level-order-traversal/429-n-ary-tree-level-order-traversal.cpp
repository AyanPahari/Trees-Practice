/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root == NULL) return res;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int>ans;
            while(size--){
                Node* u = q.front();
                q.pop();
                ans.push_back(u->val);
                for(int i=0;i<u->children.size();i++){
                    q.push(u->children[i]);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};