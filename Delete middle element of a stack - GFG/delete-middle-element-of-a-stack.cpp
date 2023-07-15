//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    void deleteX(stack<int>& s, int x){
        if(x == 1){
            s.pop();
            return;
        }
        int top = s.top();
        s.pop();
        deleteX(s, x - 1);
        s.push(top);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int n){
        int x = ceil((n + 1)/2.0);
        // cout << x << endl;
        deleteX(s, x);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends