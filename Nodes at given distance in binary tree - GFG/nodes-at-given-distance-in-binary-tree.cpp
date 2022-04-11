// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    Node* targ = NULL;
    
    void get_target(Node* root, int target){
        if(!root) return;
        if(root->data == target){
            targ = root;
        }
        get_target(root->left, target);
        get_target(root->right, target);
    }
    
    void get_parent(Node* root, unordered_map<Node*, Node*>& parent){
        // child --> parent
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* u = q.front();
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
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        get_target(root, target);
        unordered_map<Node*, Node*>parent;
        get_parent(root, parent);
        
        queue<Node*>q;
        unordered_map<Node*, bool>vis;
        q.push(targ);
        vis[targ] = true;
        int dist = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            while(size--){
                Node* u = q.front();
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
        vector<int>res;
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            res.push_back(u->data);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends