//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int helper(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == s.size() || j == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans1 = helper(i, j + 1, s, dp);
        int ans2 = helper(i + 1, j, s, dp);
        int ans3 = 0;
        if(i != j && s[i] == s[j]){
            ans2 = 1 + helper(i + 1, j + 1, s, dp);
        }
        return dp[i][j] = max(ans1, max(ans2, ans3));
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    vector<vector<int>> dp(str.size(), vector<int>(str.size(), -1));
		    return helper(0, 0, str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends