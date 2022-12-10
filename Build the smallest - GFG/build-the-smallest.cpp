//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char> st;
    for(int i = 0; i < num.size(); i++){
        while(st.size() != 0 && k > 0 && num[i] < st.top()){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(k){
        ans = ans.substr(0, ans.size() - k);
    }
    int count = 0;
    for(int i = 0; i < ans.size(); i++){
        if(ans[i] == '0') count++;
        else break;
    }
    if(count == ans.size()) return "0";
    return ans.substr(count);
}