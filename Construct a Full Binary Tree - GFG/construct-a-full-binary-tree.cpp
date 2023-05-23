//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
    Node* helper(int i, int j, int ii, int jj, int pre[], int preMirror[]){
        if(i > j) return NULL;
        Node* root = new Node(pre[i]);
        if(i == j){
            return root;
        }
        int x = i + 1;
        int xx = ii + 1;
        while(preMirror[xx] != pre[x]) xx++;
        int size = jj - xx + 1;
        root->left = helper(i + 1, i + size, xx, jj, pre, preMirror);
        root->right = helper(i + size + 1, j, ii + 1, xx - 1, pre, preMirror);
        return root;
        
        
    }
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        return helper(0, size - 1, 0, size - 1, pre, preMirror);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends