//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end());
        // cout << "1" << endl;
        vector<vector<int>> ans;
        ans.push_back(range[0]);
        for(int i = 1; i < n; i++){
            // cout << "Done1" << endl;
            if(ans.back()[1] >= range[i][0]){
                ans.back()[1] = max(ans.back()[1], range[i][1]);
            }
            else{
                ans.push_back(range[i]);
            }
        }
        vector<int> arr(ans.size());
        arr[0] = ans[0][1] - ans[0][0] + 1;
        // cout << arr[0] << " ";
        for(int i = 1; i < ans.size(); i++){
            arr[i] = arr[i - 1] + ans[i][1] - ans[i][0] + 1;
            // cout << arr[i] << " ";
        }
        // cout << "Done" << endl;
        vector<int> temp(q);
        for(int i = 0; i < q; i++){
            int index = lower_bound(arr.begin(), arr.end(), queries[i]) - arr.begin();
            // index--;
            // if(index < 0) index++;
            // cout << index << endl;
            // cout << index << endl;
            if(index == arr.size()){
                temp[i] = -1;
                continue;
            }
            // if(arr[index] < queries[i]){
            //     temp[i] = -1;
            //     continue;
            // }
            int t = index;
            if(index > 0) index = queries[i] - arr[index - 1];
            else index = queries[i];
            index--;
            temp[i] = ans[t][0] + index;
            // 3 7
        }
        return temp;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends