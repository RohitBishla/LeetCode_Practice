//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    void reverse(Node* head){
        Node* back = NULL;
        Node* front = head->next;
        while(front != NULL){
            head->next = back;
            back = head;
            head = front;
            front = front->next;
        }
        head->next = back;
        return;
    }
    
public:
    Node* sortList(Node* head)
    {
        Node* negative = new Node;
        Node* nTail = negative;
        Node* postive = new Node;
        Node* pTail = postive;
        Node* temp = head;
        // cout << negative->data << endl;
        while(temp != NULL){
            // cout << temp->data << endl;
            if(temp->data > 0){
                pTail->next = temp;
                pTail = temp;
                temp = temp->next;
                pTail->next = NULL;
            }
            else{
                nTail->next = temp;
                temp = temp->next;
                nTail = nTail->next;
                nTail->next = NULL;
            }
        }
        negative = negative->next;
        postive = postive->next;
        if(negative == NULL) return postive;
        reverse(negative);
        negative->next = postive;
        return nTail;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends