//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i = 0, j = 0;
        int ans = 0;
        while(j < n){
            if(arr[j] == 'O'){
                if(m > 0){
                    m--;
                    // j++;
                }
                else{
                    while(i < j && m == 0){
                        if(arr[i] == 'O'){
                            m++;
                        }
                        i++;
                    }
                    // j++;
                    m--;
                }
            }
            ans = max(ans, j - i + 1);
            j++;
            // cout << i << ", " << j  << ", " << m << endl;
            
        }
        // ans = max(ans, j - i + 1);
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends