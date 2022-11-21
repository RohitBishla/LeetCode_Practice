//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    void helper(int n, vector<int>& temp, vector<vector<int>>& ans, int maxi){
        if(n == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = min(n, maxi); i > 0; i--){
            temp.push_back(i);
            helper(n - i, temp, ans, i);
            temp.pop_back();
        }
    }
	public:
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n, temp, ans, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends