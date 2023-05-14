//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
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
    long long helper(int i, vector<int>& A, vector<long long>& dp){
        if(i >= A.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long ans = 0;
        if(A[i] > 0){
            ans = A[i];
            ans = ans + helper(i + 1, A, dp);
        }
        else{
            ans = A[i];
            ans = ans + helper(i + 1, A, dp);
            long long temp = helper(i + 2, A, dp);
            if(i < A.size() - 1){
                temp += A[i + 1];
            }
            ans = max(temp, ans);
        }
        return dp[i] = ans;
        
    }
  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<long long> dp(N, -1);
        return helper(0, A, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends