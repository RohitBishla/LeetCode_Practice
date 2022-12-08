//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans(q);
        for(int i = 0; i < q; i++){
            long long a = query[i];
            int temp = pow(a, 0.5) + 1;
            a = 0;
            vector<bool> arr(temp, true);
            arr[0] = false;
            arr[1] = false;
            for(int i = 2; i < temp; i++){
                if(arr[i]){
                    a++;
                    for(int j = 2; i*j < temp; j++){
                        arr[i*j] = false;
                    }
                }
            }
            ans[i] = a;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends