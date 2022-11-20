//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;
        queue<Node*> qu1;
        queue<Node*> qu2;
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        qu1.push(root1);
        qu2.push(root2);
        qu1.push(NULL);
        qu2.push(NULL);
        map1[root1->data]++;
        map2[root2->data]++;
        while(qu1.size() != 0 && qu2.size() != 0){
            Node* a = qu1.front();
            Node* b = qu2.front();
            qu1.pop();
            qu2.pop();
            if(a == NULL && b == NULL){
                for(auto it: map1){
                    // cout << it.first << " " << it.second << " ,  " << map2[it.first] << endl;
                    if(map2[it.first] != it.second) return false;
                }
                if(qu1.size() != 0) qu1.push(NULL);
                if(qu2.size() != 0) qu2.push(NULL);
                map1.clear();
                map2.clear();
            }
            if(a != NULL){
                if(a->left != NULL){
                    qu1.push(a->left);
                    map1[a->left->data]++;
                }
                if(a->right != NULL){
                    map1[a->right->data]++;
                    qu1.push(a->right);
                }
            }
            if(b != NULL){
                // if(a->left != NULL){
                //     qu1.push(a->left);
                //     map1[a->left->data]++;
                // }
                // if(a->right != NULL){
                //     map1[a->right->data];
                //     qu2.push(a->right);
                // }
                if(b->left != NULL){
                    qu2.push(b->left);
                    map2[b->left->data]++;
                }
                if(b->right != NULL){
                    qu2.push(b->right);
                    map2[b->right->data]++;
                }
            }
            // cout << "Yes" << endl;
        }
        // cout << qu1.size() << " " << qu2.size() << endl;
        if(qu1.size() == 0 && qu2.size() == 0) return true;
        return false;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends