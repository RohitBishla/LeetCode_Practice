//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        int left = 0;
        int right = n;
        while(left <= right){
            int mid = (left + right)/2;
            if(mid > k){
                right = mid - 1;
                continue;
            }
            int rem = k - mid;
            if(rem > m){
                left = mid + 1;
                continue;
            }
            int mini1 = INT_MIN;
            int mini2 = INT_MIN;
            if(mid - 1 >= 0) mini1 = arr1[mid - 1];
            if(rem - 1 >= 0) mini2 = arr2[rem - 1];
            int maxi1 = INT_MAX;
            int maxi2 = INT_MAX;
            if(mid < n) maxi1 = arr1[mid];
            if(rem < m) maxi2 = arr2[rem];
            int leftMax = max(mini1, mini2);
            int rightMin = min(maxi1, maxi2);
            if(leftMax <= rightMin){
                return leftMax;
            }
            else{
                if(leftMax == mini2){
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends