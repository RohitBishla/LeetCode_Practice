//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) map[arr[i]]++;
        int freq = n;
        int ans = arr[0];
        for(auto it: map){
            if(it.second == freq){
                if(ans < it.first) ans = it.first;
            }
            else if(it.second < freq){
                ans = it.first;
                freq = it.second;
            }
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