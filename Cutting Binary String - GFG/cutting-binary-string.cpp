//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    bool check(int i, int j, string& s){
        long long ans = 0;
        long long len = 0;
        if(s[j] == '0') return false;
        for(int x = i; x >= j; x--){
            if(s[x] == '1'){
                ans += (long long)(1)<<len;
            }
            len++;
        }
        long long five = 5;
        // cout << ans << endl;
        if(ans == 1) return true;
        if(ans == 0) return false;
        while(ans > 1){
            
            if(ans%five != 0) return false;
            ans /= five;
        }
        return true;
    }
    
    
    int helper(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == s.size()){
            if(check(i - 1, j, s)) return 1;
            return -1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int a = helper(i + 1, j, s, dp);
        int b = -1;
        if(check(i, j, s)){
            int c = helper(i + 1, i + 1, s, dp);
            if(c != -1) b = c + 1;
        }
        if(b == -1) return dp[i][j] = a;
        if(a == -1) return dp[i][j] = b;
        return dp[i][j] = min(a, b);
    }
    public:
    // 101, 11001, 1111101, 1001110001, 110000110101, 11110100001001 
    int cuts(string s){
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return helper(0, 0, s, dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends