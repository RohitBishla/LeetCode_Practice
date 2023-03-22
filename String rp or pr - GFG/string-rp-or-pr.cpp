//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      stack<char> st;
      long long int pr1 = 0;
      long long int rp1 = 0;
      for(int i = 0; i < S.size(); i++){
          if(S[i] == 'r'){
              if(!st.empty() && st.top() == 'p'){
                  pr1++;
                  st.pop();
              }
              else st.push(S[i]);
          }
          else st.push(S[i]);
      }
      int i = 0;
      int j = 0;
      while(!st.empty()){
          if(st.top() == 'p'){
              i++;
          }
          else if(st.top() == 'r') j++;
          else{
              rp1 += min(i, j);
              i = 0;
              j = 0;
          }
          st.pop();
      }
    //   cout << i << ", " << j << endl;
      rp1 += min(i, j);
      long long int pr2 = 0;
      long long int rp2 = 0;
      for(int i = 0; i < S.size(); i++){
          if(S[i] == 'p'){
              if(!st.empty() && st.top() == 'r'){
                  rp2++;
                  st.pop();
              }
              else st.push(S[i]);
          }
          else st.push(S[i]);
      }
    //   cout << pr1 << ", " << rp1 << endl;
      i = 0;
      j = 0;
      while(!st.empty()){
          if(st.top() == 'p'){
              i++;
          }
          else if(st.top() == 'r') j++;
          else{
              pr2 += min(i, j);
              i = 0;
              j = 0;
          }
          st.pop();
      }
      pr2 += min(i, j);
    //   cout << pr2 << ", " << rp2 << endl;
      long long int ans = max(pr1*(long long)(X) + rp1*(long long)(Y), pr2*(long long)(X) + rp2*(long long)(Y));
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends