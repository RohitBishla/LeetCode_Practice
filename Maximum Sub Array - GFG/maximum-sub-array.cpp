//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int ans1 = INT_MIN;
	    int start = 0;
	    int end = 0;
	    int tempStart = 0;
	   // int tempEnd = 0;
	    int count = 0;
	    for(int i = 0; i < n; i++){
	        if(a[i] < 0){
	            count = 0;
	            tempStart = i + 1;
	        }
	        else{
	            count += a[i];
	            if(count == ans1){
	                if(i - tempStart > end - start){
	                    start = tempStart;
	                    end = i;
	                }
	            }
	            if(count > ans1){
	                ans1 = count;
	                start = tempStart;
	                end = i;
	            }
	        }
	    }
	    vector<int> ans(end - start + 1);
	    if(ans1 < 0) return {-1};
	    for(int i = start; i <= end; i++){
	        ans[i - start] = a[i];
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends