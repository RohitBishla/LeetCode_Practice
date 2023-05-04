//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(), ranges.end());
        vector<int> right(n);
        // vector<int> left(n);
        right[n - 1] = ranges[n - 1][2];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(ranges[i][2], right[i + 1]);
        }
        // left[0] = range[0][2];
        // for(int i = 1; i < n; i++){
        //     left[i] = max(left[i - 1], range[i][2]);
        // }
        int maxi = 0;
        for(int i = 0; i < ranges.size(); i++){
            int l = i + 1;
            int r = n - 1;
            int ans = -1;
            while(l <= r){
                int mid = (l + r)/2;
                if(ranges[mid][0] < ranges[i][1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                    ans = mid;
                }
            }
            if(ans == -1){
                maxi = max(maxi, ranges[i][2]);
            }
            else{
                maxi = max(maxi, ranges[i][2] + right[ans]);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends