//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{  
    int helper(int i, int last, vector<vector<int>>& colors, vector<vector<int>>& dp){
        if(i == colors.size()) return 0;
        if(dp[i][last + 1] != -1) return dp[i][last + 1];
        int ans = INT_MAX;
        for(int x = 0; x < 3; x++){
            if(x == last) continue;
            ans = min(ans, colors[i][x] + helper(i + 1, x, colors, dp));
        }
        return dp[i][last + 1] = ans;
    }
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>> dp(N, vector<int>(4, -1));
        return helper(0, -1, colors, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends