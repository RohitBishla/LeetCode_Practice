//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> indegree(V);
        vector<vector<int>> revAdj(V);
        for(int i = 0; i < V; i++){
            indegree[i] = adj[i].size();
            for(int j = 0; j < adj[i].size(); j++){
                revAdj[adj[i][j]].push_back(i);
            }
        }
        queue<int> qu;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) qu.push(i);
        }
        vector<int> ans;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
            for(auto it: revAdj[node]){
                indegree[it]--;
                if(indegree[it] == 0) qu.push(it);
            }
        }
        sort(ans.begin(), ans.end());
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