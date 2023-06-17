//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    long long helper(int i, int last, vector<vector<int>>& arr, vector<vector<long long>>& dp){
        if(i == arr.size()){
            return abs(arr[i - 1][last]);
        }
        if(dp[i][last] != -1) return dp[i][last];
        long long temp = (long long) (abs(arr[i][0] - arr[i][1]));
        long long ans = helper(i + 1, 1, arr, dp) + (long long)(abs(arr[i - 1][last] - arr[i][0]));
        long long ans2 = helper(i + 1, 0, arr, dp) + (long long)(abs(arr[i - 1][last] - arr[i][1]));
        return dp[i][last] = min(ans, ans2) + temp;
    }
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int, pair<int, int>> map;
        for(int i = 0; i < n; i++){
            if(map.count(types[i])){
                map[types[i]].first = min(map[types[i]].first, locations[i]);
                map[types[i]].second = max(map[types[i]].second, locations[i]);
            }
            else map[types[i]] = {locations[i], locations[i]};
        }
        vector<vector<int>> arr;
        arr.push_back({0, 0});
        for(auto it: map){
            arr.push_back({it.second.first, it.second.second});
        }
        vector<vector<long long>> dp(arr.size(), vector<long long>(2, -1));
        return helper(1, 0, arr, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends