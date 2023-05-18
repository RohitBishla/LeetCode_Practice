//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int i, int j, vector<vector<int>>& matrix){
        if(i == matrix.size() || i < 0 || j < 0 || j == matrix[0].size() || matrix[i][j] == 0) return;
        matrix[i][j] = 0;
        dfs(i + 1, j, matrix);
        dfs(i, j + 1, matrix);
        dfs(i - 1, j, matrix);
        dfs(i, j - 1, matrix);
    }
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        for(int i = 0; i < N; i++){
            if(matrix[i][0]){
                dfs(i, 0, matrix);
            }
            if(matrix[i][matrix[0].size() - 1]){
                dfs(i, matrix[0].size() - 1, matrix);
            }
        }
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j]){
                dfs(0, j, matrix);
            }
            if(matrix[matrix.size() - 1][j]){
                dfs(matrix.size() - 1, j, matrix);
            }
        }
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j]){
                    ans++;
                    dfs(i, j, matrix);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends