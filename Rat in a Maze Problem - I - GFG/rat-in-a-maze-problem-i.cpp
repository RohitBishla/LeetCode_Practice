//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<char> dirC = {'R', 'D', 'U', 'L'};
    void dfs(int i, int j, int n, vector<vector<int>>& m, vector<string>& ans, string temp, vector<vector<int>>& visited){
        if(i < 0 || j < 0 || i == n || j == n || visited[i][j] || m[i][j] == 0) return;
        if(i == n - 1 && j == n - 1){
            ans.push_back(temp);
            return;
        }
        
        visited[i][j] = 1;
        for(int x = 0; x < 4; x++){
            dfs(i + dir[x].first, j + dir[x].second, n, m, ans, temp + dirC[x], visited);
        }
        visited[i][j] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        dfs(0, 0, n, m, ans, "", visited);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends