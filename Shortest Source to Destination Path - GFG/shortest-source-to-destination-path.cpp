//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<vector<int>> qu;
        qu.push({0, 0, 0});
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!qu.empty()){
            vector<int> a = qu.front();
            qu.pop();
            int i = a[0], j = a[1];
            
            if(i < 0 || j < 0 || i == N || j == M || A[i][j] == 0) continue;
            if(i == X && j == Y) return a[2];
            A[i][j] = 0;
            for(auto it: dir) qu.push({i + it.first, j + it.second, a[2] + 1});
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends