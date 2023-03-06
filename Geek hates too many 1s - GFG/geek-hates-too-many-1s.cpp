//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        int count = 0;
        // int t = 7&2;
        // cout << t << endl;
        for(int i = 31; i >= 0; i--){
            int temp = 1 << i;
            int x = temp&n;
            if(x > 0){
                count++;
                // cout << i << ", " << count << endl;
            }
            else{
                count = 0;
            }
            // cout << temp << ", " << count << endl;
            if(count == 3){
                n = n^(temp);
                count = 0;
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends