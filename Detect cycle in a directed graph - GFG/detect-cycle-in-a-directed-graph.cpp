//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> qu;
        vector<int> indegree(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) qu.push(i);
        }
        vector<int> top;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            top.push_back(node);
            for(int i = 0; i < adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0) qu.push(adj[node][i]);
            }
        }
        if(top.size() == V) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends