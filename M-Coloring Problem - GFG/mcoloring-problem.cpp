//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    bool helper(int i, bool graph[101][101], int m, int n, vector<int>& col){
        if(i == n) return true;
        unordered_map<int, int> map;
        for(int j = 0; j < n; j++){
            if(graph[i][j]) map[col[j]]++;
        }
        for(int j = 0; j < m; j++){
            if(!map.count(j)){
                col[i] = j;
                if(helper(i + 1, graph, m, n, col)) return true;
                col[i] = -1;
            }
        }
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> col(n, -1);
        return helper(0, graph, m, n, col);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends