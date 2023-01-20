//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge){
      vector<int> arr(N, 0);
      int ans = 0;
      int index = 0;
      for(int i = 0; i < N; i++){
          if(Edge[i] != -1){
              arr[Edge[i]] += i;
              if(arr[Edge[i]] > ans){
                  ans = arr[Edge[i]];
                  index = Edge[i];
              }
          }
      }
      return index;
      
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends