//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    int helper(int left, int right, vector<int>& a, vector<vector<int>>& dp){
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];
        int ans = 0;
        for(int i = left; i <= right; i++){
            ans = max(ans, a[left - 1]*a[i]*a[right + 1] + helper(left, i - 1, a, dp) + helper(i + 1, right, a, dp));
        }
        return dp[left][right] = ans;
    }
    public:
        int maxCoins(int N, vector <int> &a){
            a.insert(a.begin(),1);
            a.push_back(1);
            // a.push_front(1);
            vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
            return helper(1, a.size() - 2, a, dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends