//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution{
    struct Node* merge(struct Node* head1, struct Node* head2){
        Node* mainHead = new Node(-1);
        struct Node* tail = mainHead;
        while(head1 != NULL && head2 != NULL){
            if(head1->data == head2->data){
                tail->next = head1;
                head1 = head1->next;
                head2 = head2->next;
            }
            else if(head1->data > head2->data){
                tail->next = head2;
                head2 = head2->next;
            }
            else{
                tail->next = head1;
                head1 = head1->next;
            }
            tail = tail->next;
        }
        if(head1 != NULL) tail->next = head1;
        if(head2 != NULL) tail->next = head2;
        return mainHead->next;
    }
    struct Node* sort(struct Node* head){
        if(head == NULL || head->next == NULL) return head;
        // cout << head->data << endl;
        struct Node* slow = head;
        struct Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        struct Node* newHead = slow->next;
        slow->next = NULL;
        head = sort(head);
        newHead = sort(newHead);
        return merge(head, newHead);
    }
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2){
        // cout << head1->data << endl;
        head1 = sort(head1);
        head2 = sort(head2);
        return merge(head1, head2);
        
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends