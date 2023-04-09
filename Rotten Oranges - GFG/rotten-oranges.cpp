//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> qu;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2) qu.push({i, j});
            }
        }
        qu.push({-1, -1});
        while(!qu.empty()){
            pair<int, int> p = qu.front();
            qu.pop();
            int i = p.first;
            int j = p.second;
            if(p.first == -1){
                if(!qu.empty()){ 
                    qu.push({-1, -1});
                    ans++;
                }
                
            }
            else{
                if(i > 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    qu.push({i - 1, j});
                }
                if(j > 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    qu.push({i, j - 1});
                }
                if(i < grid.size() - 1 && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    qu.push({i + 1, j});
                }
                if(j < grid[0].size() - 1 && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    qu.push({i, j + 1});
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends