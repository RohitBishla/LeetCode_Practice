vector<int> topologyBFS(vector<vector<int>>& graph, int v){
    vector<int> indegree(v, 0);
    for(int i = 0; i < v; i++){
        for(int j = 0; j < graph[i].size(); j++){
            indegree[graph[i][j]]++;
        }
    }
    queue<int> qu;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0) qu.push(i);
    }
    vector<int> ans;
    while(!qu.empty()){
        int node = qu.front();
        ans.push_back(node);
        qu.pop();
        for(auto it: graph[node]){
            if(indegree[it] > 0){
                indegree[it]--;
                if(indegree[it] == 0){
                    qu.push(it);
                }
            }
        }
    }
    
    if(ans.size() != v){
        vector<int> temp;
        return temp;
    }
    return ans;
}
class Solution {
//     bool DAG(int i, vector<vector<int>>& graph, vector<int>& visited, vector<int>& dfsVisited){
//         visited[i] = 1;
//         dfsVisited[i] = 1;
//         for(auto it: graph[i]){
//             if(!visited[it]){
//                 if(!DAG(it, graph, visited, dfsVisited)) return false;
//             }
//             else if(dfsVisited[it]) return false;
//         }

//         dfsVisited[i] = 0;
//         return true;
//     }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[a].push_back(b);
        }
        // vector<int> temp;
        // vector<int> visited(numCourses, 0);
        // vector<int> dfsVisited(numCourses, 0);
        // for(int i = 0; i < numCourses; i++){
        //     if(!visited[i]){
        //         if(!DAG(i, graph, visited, dfsVisited)) return temp;
        //     }
        // }
        // // reverse(ans.begin(), ans.end());
        vector<int> ans = topologyBFS(graph, numCourses);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};