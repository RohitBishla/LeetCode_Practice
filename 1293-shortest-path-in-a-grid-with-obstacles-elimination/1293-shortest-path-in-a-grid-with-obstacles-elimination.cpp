class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        qu.push({0, 0, 0, k});
        while(!qu.empty()){
            vector<int> a = qu.front();
            qu.pop();
            int i = a[0], j = a[1];
            if(i < 0 || j < 0 || i == n || j == m ) continue;
            if(grid[i][j] == 1){
                if(a[3] > 0){
                    a[3]--;
                }
                else continue;
            }
            if(i == n - 1 && j == m - 1) return a[2];
            if(visited[i][j] != -1 && visited[i][j] >= a[3]) continue;
            a[2]++;
            visited[i][j] = a[3];
            qu.push({i + 1, j, a[2], a[3]});
            qu.push({i, j + 1, a[2], a[3]});
            qu.push({i - 1, j, a[2], a[3]});
            qu.push({i, j - 1, a[2], a[3]});
            // visited[i][j] = 0;
        }
        return -1;
    }
};