//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<int> visited(leaves + 1, 0);
        // sort(frogs, frogs + N);
        for(int i = 0; i < N; i++){
            int step = frogs[i];
            if(step <= leaves && visited[step]) continue;
            while(step <= leaves){
                // if(visited[step] == 1) break;
                visited[step] = 1;
                step += frogs[i];
            }
        }
        int ans = 0;
        for(int i = 1; i < leaves + 1; i++){
            if(!visited[i]) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends