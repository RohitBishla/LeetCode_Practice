//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    long long ans;
    pair<long long int, long long int> dfs(int i, vector<vector<int>>& adj, vector<int>& A){
        long long int a = -1e9;
        long long int b = -1e9;
        if(adj[i].size() == 0){
            a = A[i];
            b = (-1)*A[i];
        }
        for(auto it: adj[i]){
            pair<long long int, long long int> p = dfs(it, adj, A);
            a = max(a, A[i] + p.second);
            b = max(b, A[i]*(-1) + p.first);
        }
        ans = max(a, ans);
        // ans = max(b, ans);
        return {a, b};
    }
    
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<vector<int>> adj(N);
        for(int i = 1; i < N; i++){
            adj[P[i] - 1].push_back(i);
        }
        ans = -1e9;
        dfs(0, adj, A);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends