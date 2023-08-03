//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> dis(N, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        dis[0] = 0;
        qu.push({0, 0});
        while(!qu.empty()){
            pair<int, int> p = qu.top();
            qu.pop();
            for(auto it: adj[p.second]){
                int cost = it.second + p.first;
                if(dis[it.first] > cost){
                    dis[it.first] = cost;
                    qu.push({cost, it.first});
                }
            }
        }
        for(int i = 0; i < N; i++) if(dis[i] == INT_MAX) dis[i] = -1;
        return dis;
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