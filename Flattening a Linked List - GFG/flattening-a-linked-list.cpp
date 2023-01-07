//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/
Node* merge(Node* n1,Node* n2)

    {

        Node* tmp=new Node(0);

        Node* res=tmp;

        

        while(n1 != NULL && n2 != NULL)

        {

            if(n1->data <= n2->data)

            {

                tmp->bottom=n1;

                tmp=tmp->bottom;

                n1=n1->bottom;

            }

            else

            {

                tmp->bottom=n2;

                tmp=tmp->bottom;

                n2=n2->bottom;

            }

        }

        

        if(n1)

        {

            tmp->bottom=n1;

        }

        else

        {

            tmp->bottom=n2;

        }

        

        return res->bottom;

    }
Node* sort(Node* root1, Node* root2){
    // if(root1->data > root2->data){
    //     Node* temp = root2;
    //     root1 = root2;
    //     root2 = temp;
    // }
        
    Node* head = new Node(0);
    Node* tail = head;
    
    while(root1 != NULL && root2 != NULL){
        if(root2->data < root1->data){
            tail->bottom = root2;
            root2 = root2->bottom;            
            // Node* temp = root2;
            // root2 = root2->bottom;
            // tail->bottom = temp;
            // tail = temp;
            // temp->bottom = root1;
        }
        else{
            tail->bottom = root1;
            root1 = root1->bottom;
        }
        tail = tail->bottom;
    }
    if(root2 != NULL){
        tail->bottom = root2;
    }
    else{
        tail->bottom = root1;
    }
    return head->bottom;
}

Node* change(Node* root){
    if(root == NULL) return NULL;
    root->next = change(root->bottom);
    // root->bottom = NULL;
    return root;
}


class Solution {
public:
    Node *flatten(Node *root){
        if(root == NULL || root->next == NULL) return root;
        // cout << root->bottom->bottom->data << endl;
        Node* head = root;
        root->next = flatten(root->next);
        root = sort(root, root->next);
        return root;
        // root = sort(root, root->next);
        // return root;
        // while(root != NULL && root->next != NULL){
            Node* temp = root->next->next;
            Node* one = root;
            Node* two = root->next;
            one->next = NULL;
            two->next = NULL;
            Node* main = sort(one, two);
            // cout << main->data << endl;
            main->next = temp;
            root = main;
            return root;
        // }
        // while(head != NULL){
        //     cout << head->data << " ";
        //     head = head->bottom;
        // }
        // cout << endl;
        // Node* temp = root;
        // while(temp != NULL){
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << endl;
    
        
        
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends