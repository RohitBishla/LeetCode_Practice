//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    int ans = INT_MIN;
    void dfs(Node* root, int summ, int temp){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            ans = max(ans, temp - summ - root->data);
            return;
        }
        dfs(root->left, summ + root->data, temp);
        dfs(root->right, summ + root->data, temp);
    }
    void helper(Node* root, int target, int summ){
        if(root == NULL) return;
        if(root->data == target){

            if(root->left == NULL && root->right == NULL) ans = summ;
            // if(root->left != NULL)
                dfs(root->left, 0, summ);
            // if(root->right != NULL)
                dfs(root->right, 0, summ);
        }
        else if(root->data > target){
            helper(root->left, target, summ + root->data);
        }
        else{
            helper(root->right, target, summ + root->data);
        }
    }
public:
    int maxDifferenceBST(Node *root,int target){
        if(root == NULL){
            return -1;
        }
        // if(root->data == target) return -1;
        ans = INT_MIN;
        helper(root, target, 0);
        if(ans == INT_MIN) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends