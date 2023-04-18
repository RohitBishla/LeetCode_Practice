//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
    int len;
    int ans;
    vector<long long int> helper(Node* root){
        if(root == NULL) return {0, 0, -1, -1, 1};

        vector<long long int> left = helper(root->left);
        vector<long long int> right = helper(root->right);
        long long int temp = left[1] + right[1]+ root->data;
        int temp2 = left[0] + right[0] + 1;
        bool flag = left[4] & right[4];
        if(!flag){
            return {0, 0, -1, -1, 0};
        }
        if(left[3] != -1 && root->data <= left[3]){
            return {0, 0, -1, -1, 0};
        }
        if(left[3] == -1){
            left[3] = root->data;
            left[2] = root->data;
        }
        if(right[2] != -1 && root->data >= right[2]){
            return {0, 0, -1, -1, 0};
        }
        if(right[2] == -1){
            right[2] = root->data;
            right[3] = root->data;
        }
        // cout << temp2 << " " << temp << endl;
        if(temp == ans){
            // cout << "Done" << endl;
            len = min(temp2, len);
        }
        return {temp2, temp, left[2], right[3], 1};
        
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        ans = target;
        len = INT_MAX;
        helper(root);
        if(len == INT_MAX) return -1;
        return len;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends