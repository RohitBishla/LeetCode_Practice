//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    int mod = pow(10, 9) + 7;
    long long helper(long long i, long long int n, int x, vector<vector<long long>>& dp){
        if(n == 0){
            return 1;
        }
        if(n < 0) return 0;
        long long temp = pow(i, x);
        if(temp > n) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        long long ans = helper(i + 1, n, x, dp);
        
        temp = helper(i + 1, n - temp, x, dp);
        return dp[i][n] = (ans + temp)%mod;
        
    }
    public:
    int numOfWays(int n, int x)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return helper(1, n, x, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends