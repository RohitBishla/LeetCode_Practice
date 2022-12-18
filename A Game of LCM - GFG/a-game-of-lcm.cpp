//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    long long int helper(long long N){
        if(N < 3) return N;
        long long ans = N*(N - 1);
        long long b = ans;
        b *= ((N - 2))/__gcd(ans, N - 2);
        b *= ((N - 3))/__gcd(b, N - 3);
        N -= 2;
        int a = 0;
        // cout << ans << ", " << b << endl;
        for(long long int i = N; i > 0; i--){
            if(__gcd(ans, i) == 1){
                ans *= i;
                a++;
            }
            if(a == 2) break;
        }
        return max(ans, b);
    }
  public:
    long long maxGcd(long long int N) {
        return max(helper(N - 1), helper(N));
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends