//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int mod = pow(10, 9) + 7;
    unordered_map<int, int> map;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int factor(int x){
        int ans = 0;
        for(int i = 0; i < prime.size(); i++){
            if(x%prime[i] == 0){
                ans += 1 << i;
                x /= prime[i];
                if(x%prime[i] == 0) return -1;
            }
            
        }
        return ans;
    }
//     5
// 10 4 1 4 10
    long long helper(int i, vector<int>& arr, int ans, vector<vector<int>>& dp){
        if(i == arr.size()){
            if(ans == 0) return 0;
            return 1;
        }
        if(dp[i][ans] != -1) return dp[i][ans];
        long long count = helper(i + 1, arr, ans, dp);
        int temp = factor(arr[i]);
        if(temp == -1) return dp[i][ans] = count;
        int x = temp&ans;
        if(x == 0){
            x = ans|temp;
            count = (count + helper(i + 1, arr, x, dp))%mod;
        }
        
        return dp[i][ans] = count;
    }
public:
    int goodSubsets(vector<int> &arr, int n){
        for(int i = 0; i < prime.size(); i++) map[prime[i]] = i;
        vector<vector<int>> dp(n, vector<int>(1024, -1));
        return helper(0, arr, 0, dp);
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends