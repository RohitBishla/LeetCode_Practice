//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    vector<int> prime;
    int dfs(int i, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[i]) return 0;
        visited[i] = 1;
        int ans = 1;
        for(auto it: adj[i]){
            ans += dfs(it, adj, visited);
        }
        return ans;
    }
public:
    void precompute(){
        vector<bool> temp(1e6);
        for(int i = 2; i < temp.size(); i++){
            if(!temp[i]){
                for(int j = 2*i; j < temp.size(); j += i){
                    temp[j] = 1;
                }
                prime.push_back(i);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &adj){
        if(m == 0) return -1;
        // vector<vector<int>> adj(n);
        // for(int i = 0; i < g.size(); i++){
            // for(int j = 0; j < g[i].size(); j++){
            //     cout << g[i][j] << ", ";
            // }
            // cout << endl;
            // int a = g[i][0] - 1;
            // int b = g[i][0] - 1;
            // cout << a << ", " << b << endl;
            // adj[a].push_back(b);
            // adj[b].push_back(a);
        // }
        vector<int> visited(n + 1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ans = max(ans, dfs(i, adj, visited));
            }
        }
        // for(int i = 0; i <= ans; i++) cout << prime[i] << " ";
        // cout << ans << endl;
        if(ans == 0){
            return -1;
        }
        return prime[ans - 1];
    // 2-3-1
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends