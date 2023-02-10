//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int> arr(26, 0);
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }
        int len = INT_MAX;
        len = min(len, arr[0]);
        len = min(len, arr[1]);
        len = min(len, arr['l' - 'a']/2);
        len = min(len, arr['o' - 'a']/2);
        len = min(len, arr['n' - 'a']);
        return len;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends