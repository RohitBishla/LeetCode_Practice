//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int i, int p, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited){
        visited[i] = 1;
        pathVisited[i] = 1;
        for(auto it: adj[i]){
            // if(it == p) continue;
            // cout << i << ", " << it << " --- " << pathVisited[it] << endl;
            if(pathVisited[it]) return true;
            if(!visited[it]){ 
                bool temp = dfs(it, i, adj, visited, pathVisited);
            if(temp) return true;
                // pathVisited[i] = 0;
                // return false;
            }
            
        }
        pathVisited[i] = 0;
        return false;
    }
    // 3-2-1-4-5-
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // for(int i = 0; i < V; i++){
        //     for(int j = 0; j < adj[i].size(); j++) cout << adj[i][j] << " ";
        //     cout << endl;
        // }
        // 5-3-1-2-4-0
        vector<int> visited(V);
        vector<int> pathVisited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                // for(int j = 0; j < V; j++) cout << pathVisited[j] << " ";
                // cout << endl;
                bool flag = dfs(i, -1, adj, visited, pathVisited);
                // cout << i << " " << flag << endl;
                if(flag) return true;
            }
        }
        return false;
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