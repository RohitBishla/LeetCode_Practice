//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
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

class Solution {
	Node* mid1(Node* head) {
		Node* slow = head;
		Node* fast = head->next;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast == NULL) return slow;
		return slow->next;
		// a b c d
	}
	Node* reverse(Node* head) {
		if (head == NULL || head->next == NULL) return head;
		Node* tail = NULL;
		// Node* m = head;
		Node* next = head->next;
		while (next != NULL) {
			head->next = tail;
			tail = head;
			head = next;
			next = next->next;
		}
		head->next = tail;
		return head;
	}
public:
	void reorderList(Node* head) {
		// Your code here
		if (head == NULL || head->next == NULL) return;
		Node* mid = mid1(head);
		Node* head2 = mid->next;
		mid->next = NULL;
		head2 = reverse(head2);
		// cout << " Done" << endl;
		int count = 0;
		while (head != NULL && head2 != NULL) {
			Node* temp = head->next;
			head->next = head2;
			head2 = head2->next;
			head = head->next;

			head->next = temp;

			head = head->next;
		}
		// if(head2 != NULL){
		// 	// head
		// }
		return;
	}
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends