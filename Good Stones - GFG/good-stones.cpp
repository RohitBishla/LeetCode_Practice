//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    bool dfs(int i, int n, vector<int>& arr, vector<int>& visited){
        if(i < 0 || i >= n) return true;
        if(visited[i] != -1) return visited[i];
        visited[i] = 0;
        bool flag = dfs(i + arr[i], n, arr, visited);
        visited[i] = flag;
        return flag;
    }
public:
    int goodStones(int n,vector<int> &arr){
        vector<int> vis(n, -1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1){
                dfs(i, n, arr, vis);
            }
            ans += vis[i];
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends