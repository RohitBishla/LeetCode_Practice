//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s){
            string ans = "";
            int i = s.size() - 1;
            int j = s.size() - 1;
            while(i >= 0){
                string temp = "";
                while(j >= 0 && s[j] >= '0' && s[j] <= '9'){
                    temp += s[j];
                    j--;
                }
                reverse(temp.begin(), temp.end());
                // cout << temp << endl;
                ans += temp;
                if(j >= 0){
                    ans += s[j--];
                }
                i = j;
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends