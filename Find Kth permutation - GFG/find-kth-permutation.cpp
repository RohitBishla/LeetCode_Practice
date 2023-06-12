//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void helper(string& ans){
        int i = ans.size() - 2;
        while(i >= 0 && ans[i] >= ans[i + 1]){
            i--;
        }
        if(i < 0) return;
        reverse(ans.begin() + i + 1, ans.end());
        // swap(ans[i], ans[i + 1]);
        for(int j = i + 1; j < ans.size(); j++){
            if(ans[i] < ans[j]){
                swap(ans[i], ans[j]);
                break;
            }
        }
    }
public:
    string kthPermutation(int n, int k)
    {
        string ans = "";
        for(int i = 1; i <= n; i++) ans += ('0' + i);
        for(int i = 0; i < k - 1; i++){
            helper(ans);
            // cout << ans << endl;
        }
        return ans;
    }
};
//
// 1432



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends