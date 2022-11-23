//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        long long int ans = 0;
        for(int i = 1; i < sqrt(n); i++){
            if(n%i == 0){
                ans += i;
                ans += (n/i);
            }
            // cout << i << " , " << ans << endl;
        }
        // cout << sqrt(n) << " , " << pow(sqrt(n), 2) << " , " << ans<< endl;
        int x = sqrt(n);
        if(pow(x, 2) == n){
            ans += sqrt(n);
            // cout << x << ", " << ans << endl;
        } 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends