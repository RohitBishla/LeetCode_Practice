//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    void dfs(int i, long long arr[], vector<long long>& temp){
        if(temp[i] == 0) return;
        temp[i] = 0;
        long long t = arr[arr[i]];
        dfs(arr[i], arr, temp);
        arr[i] = t;
    }
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        vector<long long> temp(n, -1);
        // for(int i = 0; i < n; i++) temp[i] = -1*(arr[i] + 1);
        for(int i = 0; i < n; i++){
            if(temp[i] == -1){
                dfs(i, arr, temp);
            }
        }
    }
};

// 0 2 1


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends