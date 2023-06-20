//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        n++;
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<pair<int, int>> dic(n, {INT_MAX, INT_MAX});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dic[1] = {0, 1};
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            for(auto it: adj[p.second]){
                int d = p.first + it.second;
                if(d < dic[it.first].first){
                    dic[it.first] = {d, p.second};
                    pq.push({d, it.first});
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << dic[i].first << ", " << dic[i].second << endl;
        // }
        // cout << "DONE" << endl;
        if(dic[n - 1].first == INT_MAX) return {-1};
        vector<int> ans;
        int pos = n - 1;
        while(pos != 1){
            ans.push_back(pos);
            pos = dic[pos].second;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends