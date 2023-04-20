//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    int ans = 0;
    void dfs(Node* root, int k){
        if(k <= 0) return;
        if(root == NULL) return;
        ans += root->data;
        dfs(root->left, k - 1);
        dfs(root->right, k - 1);
    }
    pair<bool, int> helper(Node* root, int home, int k){
        if(root == NULL) return {0, 0};
        if(root->data == home){
            ans += home;
            dfs(root->left, k);
            dfs(root->right, k);
            return {true, 0};
        }
        pair<bool, int> left = helper(root->left, home, k);
        if(left.first){
            int temp = k - left.second;
            if(temp > 0)
                ans += root->data;
            dfs(root->right, temp - 1);
            return {true, left.second + 1};
        }
        pair<bool, int> right = helper(root->right, home, k);
        if(right.first){
            int temp = k - right.second;
            if(temp > 0)
                ans += root->data;
            dfs(root->left, temp - 1);
            return {true, right.second + 1};
        }
        return {false, 0};
        
    }

    public:
    int ladoos(Node* root, int home, int k)
    {
        ans = 0;
        helper(root, home, k);
        return ans;
    }


};
// 5
// 3     6
// 1 4.   10




//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends