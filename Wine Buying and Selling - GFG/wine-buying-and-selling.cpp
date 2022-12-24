//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n){
      //Code here.
      long long int ans = 0;
      int i = 0; 
      int j = 0;
      while(i < n && j < n){
        //   cout << i << ", " << j << endl;
          while(i < n && arr[i] <= 0){
              i++;
          }
          while(j < n && arr[j] >= 0){
              j++;
          }
          if(i < n && j < n){
              int temp = min(arr[i], abs(arr[j]));
              ans += (temp)*(abs(i - j));
              arr[i] -= temp;
              arr[j] += temp;
          }
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
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends