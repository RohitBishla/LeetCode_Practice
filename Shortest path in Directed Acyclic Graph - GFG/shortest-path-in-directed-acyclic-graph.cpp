//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int i, vector<vector<pair<int, int>>>& adj, vector<int>& visited, stack<int>& st){
        if(visited[i]) return;
        visited[i] = 1;
        for(auto it: adj[i]) dfs(it.first, adj, visited, st);
        st.push(i);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        stack<int> st;
        vector<int> visited(N);
        for(int i = 0; i < N; i++){
            if(!visited[i]) dfs(i, adj, visited, st);
        }
        vector<int> ans(N, INT_MAX);
        ans[0] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(ans[top] == INT_MAX) continue;
            for(auto it: adj[top]){
                ans[it.first] = min(ans[it.first], ans[top] + it.second);
            }
        }
        for(int i = 0; i < N; i++) if(ans[i] == INT_MAX) ans[i] = -1;
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends