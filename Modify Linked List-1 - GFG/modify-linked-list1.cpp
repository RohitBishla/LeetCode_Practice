//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
// a-b-c
// a-b


// b - a  , b => b - (b - a)
// int length(struct Node* head){
//     int ans = 0;
//     while(head != NULL){
//         ans++;
//         head = head->next;
//     }
//     return ans;
// }
class Solution{
    struct Node* reverse(struct Node* head){
        struct Node* tail = NULL;
        struct Node* mai = head;
        while(mai != NULL){
            struct Node* temp = mai->next;
            mai->next = tail;
            tail = mai;
            mai = temp;
        }
        return tail;
    }
    // a,b,c,d
    public:
    struct Node* modifyTheList(struct Node *head){
        struct Node* slow = head;
        struct Node* t = slow;
        // cout << "DON" << endl;
        struct Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            t = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == NULL) slow = t;
        // cout << "Done" << endl;
        // return head;
        struct Node* head2 = slow->next;
        slow->next = NULL;
        struct Node* rev = reverse(head2);
        slow = head;
        fast = rev;
        while(fast != NULL && slow != NULL){
            fast->data -= slow->data;
            fast = fast->next;
            slow = slow->next;
        }
        // cout << "Done2" << endl;
        slow = reverse(head);
        head2->next = slow;
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends