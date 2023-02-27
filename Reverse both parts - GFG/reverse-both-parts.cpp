//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
    Node* reverse1(Node* head){
        Node* h = head;
        if(h == NULL) return NULL;
        Node* tail = NULL;
        while(head->next != NULL){
            Node* n = head->next;
            head->next = tail;
            tail = head;
            head = n;
        }
        head->next = tail;
        return head;
    }
public:
   
    Node *reverse(Node *head, int k)
    {
        Node* temp = head;
        int count = 0;
        k--;
        Node* t2 = head;
        while(temp != NULL){
            if(count == k){
                Node* h2 = reverse1(temp->next);
                temp->next = NULL;
                // cout << h2->next->data << endl;
                Node* h1 = reverse1(head);
                t2->next = h2;
                return h1;
            }
            temp = temp->next;
            count++;
            
        }
        return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends