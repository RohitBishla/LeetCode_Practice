//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        long long int temp = (1LL<<(r)) - 1;
        long long int temp2 = (1<<(l - 1)) - 1;
        // string s = bitset<10>(temp).to_string();
        // string s2 = bitset<10>(temp2).to_string();
        // cout << s << " " << s2 << endl;
        temp2 = ~temp2;
        // s2 = bitset<10>(temp2).to_string();
        // cout << s2 << endl;
        temp = temp&temp2;
        // cout << temp << " " << temp2 << endl;
        // s = bitset<10>(temp).to_string();
        // cout << s << endl;
        long long int toC = y&temp;
        return x|toC;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends