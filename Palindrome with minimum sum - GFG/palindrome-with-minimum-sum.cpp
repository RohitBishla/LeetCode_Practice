//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else if(s[i] == '?'){
                s[i] = s[j];
                i++;
                j--;
            }
            else if(s[j] == '?'){
                s[j] = s[i];
                i++;
                j--;
            }
            else{
                return -1;
            }
        }
        int summ = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                continue;
            }
            if(s[i] == '?' && s[i - 1] != '?'){
                s[i] = s[i - 1];
            }
            else if(s[i] != '?' && s[i - 1] != '?'){
                summ += abs(s[i] - s[i - 1]);
            }
        }
        return summ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends