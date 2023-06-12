//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    int helper(int n, int price[], vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = helper(n - i - 1, price, dp) + price[i];
            ans = max(ans, temp);
        }
        return dp[n] = ans;
    }
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends