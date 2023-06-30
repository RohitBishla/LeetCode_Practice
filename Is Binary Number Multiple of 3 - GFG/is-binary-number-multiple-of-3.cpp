//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    int even = 0, odd = 0;
	    for(int i = s.size() - 1; i >= 0; i--){
	        if(s[i] == '1'){
	            if(i%2) odd++;
	            else even++;
	        }
	    }
	    return (odd-even)%3 == 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends