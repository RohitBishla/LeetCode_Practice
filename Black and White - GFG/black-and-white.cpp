//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
int helper(int N, int M, int i, int j){
    int ans = 0;
    N--;
    M--;
    if(j >= 2){
        if(i >= 1){
            ans++;
        }
        if(N - i >= 1){
            ans++;
        }
    }
    if(i >= 2){
        if(j >= 1){
            ans++;
        }
        if(M - j >= 1){
            ans++;
        }
    }
    if(M - j >= 2){
        if(i >= 1){
            ans++;
        }
        if(N - i >= 1){
            ans++;
        }
    }
    if(N - i >= 2){
        if(j >= 1){
            ans++;
        }
        if(M - j >= 1){
            ans++;
        }
    }
    return ans;
}
long long numOfWays(int N, int M)
{
    // write code here
    int mod = pow(10, 9) + 7;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            long long total = N*M - 1;
            total -= helper(N, M, i, j);
            ans = (ans + total)%mod;
        }
    }
    return ans;
}