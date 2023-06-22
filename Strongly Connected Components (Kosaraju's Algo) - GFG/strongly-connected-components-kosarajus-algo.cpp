//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int i, vector<vector<int>>& adj, vector<int>& visited, stack<int>& finish){
        if(visited[i]) return;
        visited[i] = 1;
        for(auto it: adj[i]) dfs(it, adj, visited, finish);
        finish.push(i);
        return;
    }
    void newDfs(int i, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[i]) return;
        visited[i] = 1;
        for(auto it: adj[i]) newDfs(it, adj, visited);
        return;
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> finish;
        vector<int> visited(V, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, finish);
            }
        }
        vector<vector<int>> rAdj(V);
        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[i].size(); j++){
                rAdj[adj[i][j]].push_back(i);
            }
        }
        for(int i = 0; i < V; i++) visited[i] = 0;
        int ans = 0;
        while(!finish.empty()){
            int x = finish.top();
            finish.pop();
            
            if(!visited[x]){
                ans++;
                newDfs(x, rAdj, visited);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends