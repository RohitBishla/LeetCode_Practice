//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> GeekNum) {
        vector<long long int> arr(n);
        if(n <= k) return GeekNum[n - 1];
        arr[0] = GeekNum[0];
        for(int i = 1; i < k; i++){
            arr[i] = arr[i - 1] + (long long)GeekNum[i];
        }
        arr[k] = 2*arr[k - 1];
        for(int i = k + 1; i < n; i++){
            // cout << arr[i - 1] << endl;
            long long int temp = arr[i - 1] - arr[i - k - 1];
            arr[i] = arr[i - 1] + temp;
        }
        // for(int i = 0; i < n; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        return arr[n - 1] - arr[n - 2];
        
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends