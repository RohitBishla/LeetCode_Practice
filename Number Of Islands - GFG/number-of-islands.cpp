//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class dsu{
public:
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv) return;
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
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
    int pos(int i, int j, int m){
        return i*m + j;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &oper) {
        vector<int> ans(oper.size());
        dsu ds(n*m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < oper.size(); i++){
            
            int a = oper[i][0];
            int b = oper[i][1];
            if(visited[a][b]){
                ans[i] = ans[i - 1];
                continue;
            }
            count++;
            visited[a][b] = 1;
            for(auto it: dir){
                int x = oper[i][0] + it.first;
                int y = oper[i][1] + it.second;
                if(x >= 0 && y >= 0 && x < n && y < m && visited[x][y]){
                    int par = ds.findUParent(pos(x, y, m));
                    int myPar = ds.findUParent(pos(a, b, m));
                    if(par != myPar){
                        count--;
                        ds.unionBySize(pos(x, y, m), pos(a, b, m));
                    }
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends