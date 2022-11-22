//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    int n = nums.size();
	    vector<int> smaller(n);
	    vector<int> larger(n);
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < i; j++){
	            if(nums[i] > nums[j]) smaller[i]++;
	        }
	        for(int j = i + 1; j < n; j++){
	            if(nums[j] > nums[i]) larger[i]++;
	        }
	    }
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        ans += smaller[i]*larger[i];
	    }
	    return ans;
	   // int count = 0;
	   // 
	   // for(int i = 0; i < n; i++){
	   //     for(int j = i + 1; j < n; j++){
	   //         for(int k = j + 1; k < n;  k++){
	   //             if(nums[i] < nums[j] && nums[j] < nums[k]) count++;
	   //         }
	   //     }
	   // }
	   // return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends