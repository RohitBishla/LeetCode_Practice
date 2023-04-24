//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    void helper(vector<int>& arr, vector<int>& ans){
        stack<int> st;
        st.push(arr.size() - 1);
        int i = arr.size() - 2;
        while(i >= 0){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else{
                // cout << st.top() << endl;
                ans[i] = st.top();
            }
            st.push(i);
            i--;
        }
        while(!st.empty()) st.pop();
        st.push(0);
        i = 1;
        while(i < arr.size()){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                if(ans[i] == -1 || ((i - st.top() <= ans[i] - i) )){
                    if(ans[i] != -1 && (i - st.top()) == (ans[i] - i)){
                        if(arr[ans[i]] >= arr[st.top()]) ans[i] = st.top();
                    }
                    else
                        ans[i] = st.top();
                }   
            }
            st.push(i);
            i++;
        }
        return;
    }
public:
    vector<int> nearestSmallerTower(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        helper(arr, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends