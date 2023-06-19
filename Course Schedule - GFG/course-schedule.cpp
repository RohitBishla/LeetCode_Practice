//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) {
        queue<int> qu;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            indegree[pre[i][1]]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) qu.push(i);
        }
        vector<int> ans;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            ans.push_back(node);
            for(int i = 0; i < adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(indegree[adj[node][i]] == 0) qu.push(adj[node][i]);
            }
        }
        // for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        
        if(ans.size() != n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends