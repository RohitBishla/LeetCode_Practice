//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int mod = pow(10, 9) + 7;
    long long int helper(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<long long int>>& dp){
         if(i > n || j > m) return 0;
         if(grid[i][j] == 0) return 0;
        if(i == n && j == m) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
       
        return dp[i][j] = (helper(i + 1, j, n, m, grid, dp) + helper(i, j + 1, n, m, grid, dp))%mod;
    }
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<long long int>> dp(n, vector<long long int>(m, -1));
        return helper(0, 0, n - 1, m - 1, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends