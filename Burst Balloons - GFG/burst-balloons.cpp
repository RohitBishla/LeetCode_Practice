//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int helper(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MIN;
        for(int x = i; x <= j; x++){
            ans = max(ans, arr[i - 1]*arr[x]*arr[j + 1] + helper(i, x - 1, arr, dp) + helper(x + 1, j, arr, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(int N, vector<int> &arr) {
        arr.push_back(1);
        arr.push_back(1);
        for(int i = N; i > 0; i--){
            swap(arr[i], arr[i - 1]);
        }
        vector<vector<int>> dp(N + 2, vector<int>(N + 2, -1));
        return helper(1, N, arr, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends