//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int l = 0, r = 0, d = 0, u = 0;
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                x--;
                l = min(x, l);
            }
            else if(s[i] == 'R'){
                x++;
                r = max(r, x);
            }
            else if(s[i] == 'D'){
                y--;
                d = min(d, y);
            }
            else{
                y++;
                u = max(u, y);
            }
        }
        l = abs(l);
        d = abs(d);
        int temp = r + l + 1;
        if(temp > m) return false;
        temp = u + d + 1;
        if(temp > n) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends