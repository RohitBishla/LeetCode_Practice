class Solution {
    int helper(vector<vector<int>>& grid, int x){
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(grid[i][x] == -1 && (x == 0 || grid[i][x - 1] == 1)) return -1;
            if(grid[i][x] == 1 && (x == m - 1 || grid[i][x + 1] == -1)) return -1;
            x += grid[i][x];
        }
        return x;
    }
    
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++){
            ans[i] = helper(grid, i);
        }
        return ans;
    }
};