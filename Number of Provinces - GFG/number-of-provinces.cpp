//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[i]) return;
        visited[i] = 1;
        for(int j = 0; j < visited.size(); j++){
            if(adj[i][j]) dfs(j, adj, visited);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> visited(V, 0);
        int ans = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                ans++;
                dfs(i, adj, visited);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends