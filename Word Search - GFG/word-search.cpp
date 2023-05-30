//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int n, m;
    bool dfs(int i, int j, int x, string& word, vector<vector<char>>& board, vector<vector<int>>& visited){
        if(word.size() == x) return true;
        if(i < 0 || j < 0 || i == n || j == m || visited[i][j]) return false;
        if(board[i][j] != word[x]) return false;
        visited[i][j] = 1;
        bool flag = dfs(i + 1, j, x + 1, word, board, visited);
        if(flag) return true;
        if(dfs(i - 1, j, x + 1, word, board, visited)) return true;
        if(dfs(i, j + 1, x + 1, word, board, visited)) return true;
        if(dfs(i, j - 1, x + 1, word, board, visited)) return true;
        visited[i][j] = 0;
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == board[i][j]){
                    if(dfs(i, j, 0, word, board, visited)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends