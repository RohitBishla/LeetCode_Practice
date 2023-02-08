//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
    long long int helper(int a, int b, int n){
        long long ans = n;
        ans *= n;
        long long int temp = a*n;
        temp = temp + b*n - a*b;
        return ans - temp;
    }
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<long long int> ans(k);
      unordered_map<int, int> row;
      unordered_map<int, int> col;
      for(int i = 0; i < k; i++){
          row[arr[i][0]] = 1;
          col[arr[i][1]] = 1;
          ans[i] = helper(row.size(), col.size(), n);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends