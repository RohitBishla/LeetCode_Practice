//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int slow = 0;
        map<int, int> map;
        int ans = 0;
        for(int i = 0; i < N; i++){
            map[arr[i]]++;
            auto it = map.end();
            it--;
            if(it->first - (map.begin())->first > 1){
                map[arr[slow]]--;
                if(map[arr[slow]] == 0) map.erase(arr[slow]);
                slow++;
            }
            ans = max(ans, i - slow + 1);
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
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends