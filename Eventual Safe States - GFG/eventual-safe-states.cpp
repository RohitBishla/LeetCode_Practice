//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool dfs(int i, vector<int>& pathVisited, vector<int>& visited, vector<int> adj[]){
        if(pathVisited[i]) return true;
        if(visited[i]) return false;
        visited[i] = 1;
        pathVisited[i] = 1;
        for(auto it: adj[i]){
            if(dfs(it, pathVisited, visited, adj)) return true;
        }
        pathVisited[i] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, pathVisited, visited, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(pathVisited[i] == 0) ans.push_back(i);
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends