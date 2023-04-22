//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = {arr[i], i};
        }
        sort(nums.begin(), nums.end());
        vector<long long> ans(n);
        long long summ = 0;
        long long temp = 0;
        temp = nums[0].first;
        for(int i = 1; i < n; i++){
            if(nums[i].first == nums[i - 1].first){
                temp += (long long)nums[i].first;
                ans[nums[i].second] = summ;
            }
            else{
                summ += temp;
                ans[nums[i].second] = summ;
                temp = nums[i].first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends