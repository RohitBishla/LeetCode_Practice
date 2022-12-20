//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
    
        // +- => (arr[i] - i) - (arr[j] - j)
        // -- => (arr[j] + j) - (arr[i] + i)
        int a = INT_MIN;
        int b = INT_MAX;
        
        int x = INT_MIN;
        int y = INT_MAX;
        for(int i = 0; i < n; i++){
            a = max(a, arr[i] - i);
            b = min(b, arr[i] - i);
            
            x = max(x, arr[i] + i);
            y = min(y, arr[i] + i);
        }
        int ans = max(a - b, x - y);
        ans = max(ans, max(b - a, y - x));
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends