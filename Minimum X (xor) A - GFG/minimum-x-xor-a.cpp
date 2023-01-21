//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int count = 0;
        for(int i = 0; i < 32; i++){
            if(b & 1 << i) count++;
        }
        int ans = 0;
        for(int i = 31; i >= 0 && count > 0; i--){
            if(a & 1 << i){
                count--;
                ans += (1 << i);
            }
        }
        for(int i = 0; i < 32 && count > 0; i++){
            if((ans & 1 << i) == 0){
                ans += (1 << i);
                count--;
            }
        }
        return ans;
        // cout << count << endl;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends