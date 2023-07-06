//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool comp(pair<int, int>& a, pair<int, int>& b){
    if(a.second > b.second){
        return false;
    }
    else if(a.second < b.second) return true;
    if(a.first > b.first) return true;
    return false;
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            arr[i] = {start[i], end[i]};
        }
        sort(arr.begin(), arr.end(), comp);
        int ans = 0;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(arr[i].first > last){
                last = arr[i].second;
                ans++;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends