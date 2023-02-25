//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int i = 0;
        int j = 0;
        // if(flag) return false;
        while(i < S.size() && j < T.size()){
            if(T[j] >= 'A' && T[j] <= 'Z'){
                if(S[i] != T[j]) return false;
                i++;
                j++;
            }
            else{
                int temp = 0;
                while(j < T.size() && (T[j] < 'A' || T[j] > 'Z')){
                    temp = temp*10 + int(T[j] - '0');
                    j++;
                }
                // int count = T[j] - '0';
                i += temp;
                // j++;
            }
        }
        if(i != S.size() || j != T.size()) return false;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends