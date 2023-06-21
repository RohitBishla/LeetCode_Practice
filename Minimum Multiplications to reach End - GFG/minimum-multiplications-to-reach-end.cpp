//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int mod = 1e5;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> visited(mod, 0);
        visited[start] = 1;
        queue<int> qu;
        qu.push(start);
        qu.push(-1);
        int ans = 0;
        while(!qu.empty()){
            int p = qu.front();
            qu.pop();
            if(p == end) return ans;
            if(p == -1){
                ans++;
                if(!qu.empty()) qu.push(-1);
            }
            else{
                for(auto it: arr){
                    int temp = (it*p)%mod;
                    
                    if(!visited[temp]){
                        visited[temp] = 1;
                        qu.push(temp);
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends