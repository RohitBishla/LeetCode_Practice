//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
        int i = 0;
        int j = n - 1;
        k--;
        while(i <= j){
            int mid = (i + j)/2;
            int index = mid + lower_bound(arr2, arr2 + m, arr1[mid]) - arr2;
            int index2 = mid + upper_bound(arr2, arr2 + m, arr1[mid]) - arr2;
            if(index <= k && index2 >= k){
                return arr1[mid];
            }
            if(index2 < k){
                i = mid + 1;
            }
            else j = mid - 1;
        }
        return kthElement(arr2, arr1, m, n, k + 1);
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