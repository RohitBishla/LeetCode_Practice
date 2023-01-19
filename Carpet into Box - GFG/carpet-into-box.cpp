//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        //code here
        int ans = 0;
        if(C > D) swap(C, D);
        if(A > B) swap(A, B);
        while(A > C || B > D){
            ans++;
            if(B > D)
                B /= 2;
            else A /= 2;
            if(A > B) swap(A, B);
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends