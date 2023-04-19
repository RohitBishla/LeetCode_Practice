//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        // code here
        int hold = 0;
        int i = 0;
        int safe = -1;
        while(i < N){
            if(S[i] == '1'){
                if(hold > X) return false;
                hold = 0;
                safe = i + X;
                // i += X;
            }
            else{
                if(i > safe) 
                    hold++;
            }
            i++;
            // cout << hold << " " << i << " = " << safe << endl;
        }
        if(hold) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends