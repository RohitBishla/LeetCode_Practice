//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    bool check(long long int mid, vector<int>& sweetness, int k){
        long long summ = 0;
        for(int i = 0; i < sweetness.size(); i++){
            summ += sweetness[i];
            if(summ >= mid){
                summ = 0;
                k--;
            }
        }
        if(k < 0) return true;
        return false;
    }
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int left = 0;
        int right = 1e9;
        int ans = 0;
        while(left <= right){
            int mid = (left + right)/2;
            if(check(mid, sweetness, K)){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
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
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends