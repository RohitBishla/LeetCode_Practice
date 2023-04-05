//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        unordered_map<int, int> map;
        for(int i = 0; i < N; i++){
            map[arr[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            map[arr[i]]--;
            int temp = pow(arr[i], 0.5) + 1;
            for(int j = 1; j < temp; j++){
                if(arr[i]%j == 0){
                    int temp2 = arr[i]/j;
                    if(map[j] > 0 || map[temp2] > 0){
                        ans++;
                        break;
                    }
                }
            }
            map[arr[i]]++;
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

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends