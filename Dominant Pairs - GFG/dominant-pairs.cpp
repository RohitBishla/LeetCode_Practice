//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(), arr.begin() + n/2);
        sort(arr.begin() + n/2, arr.end());
        int mid = n/2;
        // 1 2 3 4
        int ans = 0;
        for(int i = mid; i < n; i++){
            int toFind = 5*arr[i];
            int index = lower_bound(arr.begin(), arr.begin() + mid, toFind) - arr.begin();
            ans += (mid - index);
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
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends