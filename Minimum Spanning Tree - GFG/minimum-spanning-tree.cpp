//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class dsu{
    vector<int> parent, size;
public:
    dsu(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    int unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(size[pu] >= size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else if(size[pu] < size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<vector<int>> edge;
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                edge.push_back({it[1], i, it[0]});
            }
        }
        sort(edge.begin(), edge.end());
        dsu d(V);
        int summ = 0;
        for(int i = 0; i < edge.size(); i++){
            int pu = edge[i][1];
            int pv = edge[i][2];
            // cout << pu << ", " << pv << "--" << d.findUParent(pu) << ", " << d.findUParent(pv) << endl;
            if(d.findUParent(pu) != d.findUParent(pv)){
                summ += edge[i][0];
                d.unionBySize(pu, pv);
            }
        }
        return summ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends