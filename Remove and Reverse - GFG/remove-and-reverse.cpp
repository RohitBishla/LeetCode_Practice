//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        unordered_map<char, int> map;
        for(int i = 0; i < S.size(); i++){
            map[S[i]]++;
        }
        int i = 0;
        int j = S.size() - 1;
        bool flag = true;
        string ans = "";
        string ans1 = "";
        while(i <= j){
            // cout << flag << ", " << S[i] << ", " << map[S[i]] << endl;
            if(flag){
                // cout << flag << ", " << S[i] << ", " << map[S[i]] << endl;
                if(map[S[i]] > 1){
                    flag = false;
                    i++;
                }
                else{
                    ans += S[i];
                    i++;
                }
                map[S[i - 1]]--;
            }
            else{
                // cout << flag << ", " << S[j] << ", " << map[S[j]] << endl;
                if(map[S[j]] > 1){
                    flag = true;
                    j--;
                }
                else{
                    ans1 += S[j];
                    j--;
                }
                map[S[j + 1]]--;
            }
        }
        // cout << ans << ", " << ans1 << endl;
        reverse(ans1.begin(), ans1.end());
        ans += ans1;
        if(!flag){
            reverse(ans.begin(), ans.end());
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends