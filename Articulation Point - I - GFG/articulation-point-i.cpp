//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int t = 1;
    void dfs(int i, int p, vector<int>& low, vector<int>& time, vector<int>& visited, vector<int>& mark, vector<int> adj[]){
        visited[i] = 1;
        low[i] = time[i] = t;
        t++;
        int count = 0;
        for(auto it: adj[i]){
            if(it == p) continue; 
            if(!visited[it]){
                count++;
                dfs(it, i, low, time, visited, mark, adj);
                low[i] = min(low[i], low[it]);
                if(time[i] <= low[it] && p != -1) mark[i] = 1;
            }
            else{
                low[i] = min(low[i], time[it]);
            }
            
            
        }
        if(count > 1 && p == -1) mark[i] = 1;
        return;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> low(V, 0);
        vector<int> time(V, 0);
        vector<int> visited(V, 0);
        vector<int> mark(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]) dfs(i, -1, low, time, visited, mark, adj);
        }
        vector<int> ans;
        for(int i = 0; i < V; i++) if(mark[i]) ans.push_back(i);
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends