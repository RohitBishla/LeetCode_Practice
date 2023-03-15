//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    int helper(int start, string& s, int m){
        int end = start + m - 1;
        int ans = 0;
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                if(i >= start && j <= end) return INT_MAX;
                ans++;
            }
            i++;
            j--;
        }
        return ans;
    }
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        if(s1.size() < s2.size()) return -1;
        int ans = INT_MAX;
        string temp = s1;
        int n = s1.size();
        int m = s2.size();
        for(int i = 0; i <= n - m; i++){
            int count = 0;
            for(int j = 0; j < m; j++){
                if(temp[i + j] != s2[j]){
                    count++;
                    temp[i + j] = s2[j];
                }
            }
            int a = helper(i, temp, m);
            if(a != INT_MAX) count += a;
            else count = INT_MAX;
            ans = min(ans, count);
            temp = s1;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends