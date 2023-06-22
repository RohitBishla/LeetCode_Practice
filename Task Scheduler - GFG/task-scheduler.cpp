//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        int ans = N;
        vector<int> arr(26);
        int maxi = 0;
        int count = 0;
        for(int i = 0; i < tasks.size(); i++){
            arr[tasks[i] - 'A']++;
            if(arr[tasks[i] - 'A'] > maxi){
                count = 1;
                maxi = arr[tasks[i] - 'A'];
            }
            else if(arr[tasks[i] - 'A'] == maxi) count++;
        }
        int temp = (maxi - 1)*(K + 1) + count;
        ans = max(ans, temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends