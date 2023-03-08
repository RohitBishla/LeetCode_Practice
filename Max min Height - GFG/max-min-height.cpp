//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    bool check(long long int ans, long long int k, int w, vector<int>& a){
        long long int temp = 0;
        vector<long long int> arr(a.size() + 1, 0);
        for(int i = 0; i < a.size(); i++){
            temp -= arr[i];
            long long int t = (long long)a[i] + temp;
            if(t >= ans) continue;
            long long int rem = ans - t;
            temp += rem;
            k -= rem;
            if(i + w < a.size()){
                // 0 1 2 3
                arr[i + w] = rem;
            }
            if(k < 0) return false;
        }
        return true;
    }
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a){
            long long left = 1;
            long long right = 1e14;
            long long mid = left;
            long long ans = mid;
            while(left <= right){
                mid = (left + right)/2;
                if(check(mid, k, w, a)){
                    // cout << mid << endl;
                    left = mid + 1;
                    ans = mid;
                }
                else{
                    // cout << mid << endl;
                    right = mid - 1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends