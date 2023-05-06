//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    bool helper(int i, int k, int target, vector<int>& coins, vector<vector<vector<int>>>& dp){
        if(target < 0 || k < 0) return false;

        if(i == coins.size()){
            if(k == 0 && target == 0) return 1;
            return 0;
        }
        if(dp[i][k][target] != -1) return dp[i][k][target];
        bool flag = helper(i + 1, k, target, coins, dp);
        if(flag) return dp[i][k][target] = 1;
        flag = helper(i, k - 1, target - coins[i], coins, dp);
        return dp[i][k][target] = flag;
    }
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1, vector<int>(target + 1, -1)));
        return helper(0, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends