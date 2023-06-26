//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1e9 + 7;
    long long binExp(long long a, int b){
        long long ans = 1;
        while(b){
            if(b&1) ans = (ans*a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return ans;
    }
public:
    int nCr(int n, int r){
        if(r > n) return 0;
        r = min(r, n - r);
        long long num = 1;
        for(int i = 0; i < r; i++){
            num = (num*n)%mod;
            n--;
        }
        long long den = 1;
        for(int i = 1; i <= r; i++) den = (den*i)%mod;
        den = binExp(den, mod - 2);
        return (num*den)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends