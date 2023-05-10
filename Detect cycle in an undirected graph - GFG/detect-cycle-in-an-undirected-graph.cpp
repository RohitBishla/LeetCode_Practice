//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int i, int p, vector<int> adj[], vector<int>& visited){
        if(visited[i]){
            return true;
        }
        bool ans = false;
        visited[i] = true;
        for(auto it: adj[i]){
            if(it == p) continue;
            ans = ans | dfs(it, i, adj, visited);
        }
        return ans;
    }
    
    bool bfs(int i, vector<int> adj[], vector<int>& visited){
        queue<pair<int, int>> qu;
        qu.push({i, -1});
        visited[i] = true;
        while(!qu.empty()){
            pair<int, int> p = qu.front();
            qu.pop();
            for(auto it: adj[p.first]){
                if(it == p.second) continue;
                if(visited[it]) return true;
                visited[it] = true;
                qu.push({it, p.first});
            }
        }
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool flag = bfs(i, adj, visited);
                if(flag) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends