//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int helper(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == j) return 1;
        else if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = helper(i + 1, j, s, dp);
        int b = helper(i, j - 1, s, dp);
        int c = 0;
        if(s[i] == s[j]){
            c = 2 + helper(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = max(a, max(b, c));
    }
  public:
    int longestPalinSubseq(string A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
        return helper(0, A.size() - 1, A, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends