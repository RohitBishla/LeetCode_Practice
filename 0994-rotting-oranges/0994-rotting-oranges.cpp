class Solution {
    void bfs(vector<vector<int>>& visited, vector<vector<int>>& time, int i, int j, int m, int n, int count){
        // cout << i << " " << j << endl;
        if(i < 0 || j < 0 || i >= m || j >= n || time[i][j] < count || visited[i][j] == 0) return;
        // cout << "Hello " << i << " " << j << " " << count << endl;
        // cout << time
        time[i][j] = min(time[i][j], count);
        bfs(visited, time, i + 1, j, m, n, count + 1);
        bfs(visited, time, i - 1, j, m, n, count + 1);
        // cout << "done" << endl;
        bfs(visited, time, i, j + 1, m, n, count + 1);
        bfs(visited, time, i, j - 1, m, n, count + 1);
        // cout << "end" << endl;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){ 
                    time[i][j] = INT_MAX;

                    // cout << time[i][j] << endl;
                    // cout << i << " " << j << endl;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    // cout << i << " " << j << endl;
                    vector<vector<int>> visited(m, vector<int>(n));
                    for(int a = 0; a < m; a++){
                        for(int b = 0; b < n; b++){
                            visited[a][b] = grid[a][b];
                        }
                    }
                    bfs(visited, time, i, j, m, n, 0);
                     // print(time);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, time[i][j]);
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};