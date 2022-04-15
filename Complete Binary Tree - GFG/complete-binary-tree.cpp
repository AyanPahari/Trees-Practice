// { Driver Code Starts

// A program to check if a given binary tree is complete or not
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));
        
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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
/* Given a binary tree, return true if the tree is complete
   else false */

bool isCompleteBT(Node* root);
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
        if(isCompleteBT(root)){
            printf ("Complete Binary Tree\n");
        }
        else{
            printf ("Not Complete Binary Tree\n");
        } 
    }
    return 0;
}




// } Driver Code Ends

    
    void solve(Node* root, unsigned long long index, unsigned long long& sum, int& count){
        if(!root) return;
        count++;
        sum += index;
        solve(root->left, 2*index, sum, count);
        solve(root->right, 2*index + 1, sum, count);
    }

    bool isCompleteBT(Node* root){
        //code here
        unsigned long long sum = 0;
        int count = 0;
        solve(root, 1, sum, count);
        return count*(count+1)/2 == sum;
    }
