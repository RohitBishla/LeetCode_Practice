//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int helper(string s, vector<int>& freq){
        // vector<int> freq(26);
        int maxx = INT_MIN;
        int minn = INT_MAX;
        // for(int i = 0; i < s.size(); i++){
        //     freq[s[i] - 'a']++;
        // }
        for(int i = 0; i < 26; i++){
            maxx = max(maxx, freq[i]);
            if(freq[i] != 0) minn = min(minn, freq[i]);
        }
        return maxx - minn;
    }
  public:
    int beautySum(string s) {
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++){
            vector<int> freq(26);
            freq[s[i] - 'a']++;
            for(int j = i + 1; j < s.size(); j++){
                freq[s[j] - 'a']++;
                ans += helper(s.substr(i, j - i + 1), freq);
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends