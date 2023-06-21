//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < times.size(); i++){
            adj[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1});
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            for(auto it: adj[p.second]){
                int d = it.second + p.first;
                if(d < dis[it.first]){
                    dis[it.first] = d;
                    pq.push({d, it.first});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, dis[i]);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends