//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int mod)
        {
            int ans = 0;
            int temp = 1;
            for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] == '1'){
                    ans = (ans + temp)%mod;
                }
                temp = (2*temp)%mod;
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends