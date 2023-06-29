//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
    bool isHappy(int n) {
        if(n == 1 || n == 7) return 1;
        if(n <= 9) return false;
        int temp = 0;
        // cout << n << endl;
        while(n){
            int t = n%10;
            n/=10;
            temp += t*t;
        }
        return isHappy(temp);
    }
public:
    int nextHappy(int N){
        while(true){
            if(isHappy(++N)) return N;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends