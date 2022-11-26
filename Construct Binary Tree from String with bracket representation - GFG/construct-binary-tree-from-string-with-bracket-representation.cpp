//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution {
	int toInt(string& s) {
		int ans = 0;
		int ten = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			ans += ((s[i] - '0') * ten);
			ten *= 10;
		}
		return ans;
	}
public:
	// function to construct tree from string
	Node *treeFromString(string str) {
		// code here
		if (str.size() == 0) return NULL;
		string s = "";
		int i = 0;
		// cout << str << endl;
		while (str[i] != '(' && str[i] != ')' && i < str.size()) {
			s += str[i];
			i++;
		}
		int a = toInt(s);
		Node* root = new Node(a);
		// root->data = 10;
		if (i == str.size()) return root;
		// cout << "Done" << s << " " << root->data << endl;

		s = str.substr(i + 1);
		int count = 0;
		i = 0;
		while (i < s.size() && count != -1) {
			if (s[i] == '(') count++;
			if (s[i] == ')') count--;
			i++;
		}
		if (i != s.size()) {
			str = s.substr(i + 1);
			str = str.substr(0, str.size() - 1);
		}
		else {
			str = "";
		}

		// cout << i << ", " << str << endl;
		s = s.substr(0, i - 1);
		// cout << s << endl;
		// cout << s << endl;

		// cout << s << " ,  " << str << endl;
		root->left = treeFromString(s);
		root->right = treeFromString(str);
		return root;
	}
};


//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends