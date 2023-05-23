//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int solve(int N, vector<int> p){
        vector<int> count(N);
        for(int i = 1; i < p.size(); i++){
            // if(i != p[i]){
                count[i]++;
                count[p[i]]++;
            // }
            
        }
        int c = 0;
        for(int i = 0; i < N; i++) if(count[i] <= 1) c++;
        // cout << c << endl;
        c = N - c; // 3
        if(c <= 1) return 0;
        return c - 1;
    }
};
// 8 - 5


//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++){
            cin >> p[i];
        }

        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}   
// } Driver Code Ends