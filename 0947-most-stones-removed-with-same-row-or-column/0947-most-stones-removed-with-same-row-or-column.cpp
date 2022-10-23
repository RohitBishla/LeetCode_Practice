class Solution {
    unordered_map<int,vector<int>> gr,gc;
    map<pair<int,int>,bool> vis; int ans,c;
    void dfs(int i,int j){
        vis[{i,j}] = true; c++;
        for(auto c:gr[i]) if(!vis[{i,c}] and j!=c) dfs(i,c);
        for(auto r:gc[j]) if(!vis[{r,j}] and r!=i) dfs(r,j);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto it:stones) gc[it[1]].emplace_back(it[0]), gr[it[0]].emplace_back(it[1]);
        for(auto it:stones) if(!vis[{it[0],it[1]}]) c=0, dfs(it[0],it[1]), ans+=c-1;
        return ans;
    }
};