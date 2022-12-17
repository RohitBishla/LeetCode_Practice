//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    int waysToBreakNumber(int N){
        long long int n = N + 1;
        int mod = pow(10, 9) + 7;
        long long int main = ((n*(n + 1))/2)%mod;
        return main;
    }
};

// 1 - 3.  2
// 2 - 6.  4
// 3 - 10. 7
// 4 - 15. 11
// 5 - 21. 16


//1 3 6 10 15 21
//   2 3 4. 5. 6
   
// nth => n(n + 1)/2 =>. 
    


// 0 0 4
// 0 4 0

// 4 0 
// 1 3
// 2 2
// 1 1 2 =>

// 0 5
// 1 4
// 2 3
// 1 2 2
// 1 1 3
// 

// 12 + 3 = 15
//  3 + 6 + 3 = 12 

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends