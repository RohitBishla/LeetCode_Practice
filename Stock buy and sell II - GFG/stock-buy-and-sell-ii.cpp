//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    int helper(int i, bool flag, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        int ans = helper(i + 1, flag, prices, dp);
        if(flag){
            int temp = helper(i + 1, !flag, prices, dp) - prices[i];
            ans = max(ans, temp);
        }
        else{
            int temp = helper(i + 1, !flag, prices, dp) + prices[i];
            ans = max(ans, temp);
        }
        return dp[i][flag] = ans;
    }
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, true, prices, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends