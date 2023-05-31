//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        sort(arr, arr + n);
        int ans = arr[0];
        int len = n;
        int i = 0;
        while(i < n){
            int count = 1;
            while(i < n - 1 && arr[i] == arr[i + 1]){
                count++;
                i++;
            }
            if(count <= len){
                len = count;
                ans = arr[i];
            }
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends