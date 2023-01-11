//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(), arr.end());
        int gap = arr[0];
        int indexGap = 0;
        int i = 1;
        arr.push_back(INT_MAX);
        int ans = 0;
        // for(int i = 0; i < N; i++){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        for(int i = 1; i < N; i++){
            // cout << arr[i] << endl;
            if(arr[i] == arr[i - 1]){
                // cout << i << endl;
                while(indexGap < i || gap == arr[indexGap] || arr[indexGap] - arr[indexGap - 1] <= 1){
                    gap = arr[indexGap] + 1;
                    indexGap++;
                    // cout << gap << ", " << indexGap << endl;
                }
                ans += gap - arr[i];
                gap++;
                // cout << "ans = " << ans << endl;
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends