//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

//User function Template for C++


// N*N = 
// N = 5
// 1 5 2 
// 1 5  3
// 1 5 2
// 1 5 5
// 1 5 0
// 1 5 

class Solution{
    vector<int> bin(int x){
        vector<int> arr(32, 0);
        // 4 => 100
        // 3 =>  11
        // 10
        int i = 0;
        while(x > 0){
            if(x%2){
                arr[i] = 1;
            }
            i++;
            x /= 2;
        }
        return arr;
    }
    // 0100000000 => 2 pow(2, 1);
    // 0000000010
    // 2^0 + 2^1
    // 1<<2 => 2^2
    // 1<<5 => 2^5\
    11
    // 2, 3, 4, 5 => 111^10 => 101
    int num(vector<int>& arr){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(arr[i] > 0)
                ans += (1<<i);
        }
        return ans;
    }
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U){
            vector<vector<int>> arr(N + 1, vector<int>(32, 0));
            for(auto it: U){
                vector<int> temp = bin(it[2]);
                for(int i = 0; i < 32; i++){
                    arr[it[0] - 1][i] += temp[i]; 
                }
                for(int i = 0; i < 32; i++){
                    arr[it[1]][i] -= temp[i];
                }
            }
            vector<int> ans(N, 0);
            ans[0] = num(arr[0]);
            for(int i = 1; i < N; i++){
                for(int j = 0; j < 32; j++){
                    arr[i][j] += arr[i - 1][j];
                }
                ans[i] = num(arr[i]);
            }
            return ans;
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends