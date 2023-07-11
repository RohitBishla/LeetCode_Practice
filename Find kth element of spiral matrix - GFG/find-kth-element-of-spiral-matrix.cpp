//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int iL = 0;
 		int iR = n - 1;
 		int jL = 0;
 		int jR = m - 1;
 		while(iL <= iR && jL <= jR){
 		    for(int j = jL; j <= jR; j++){
 		        k--;
 		        if(k == 0) return a[iL][j];
 		    }
 		    iL++;
 		    for(int i = iL; i <= iR; i++){
 		        k--;
 		        if(k == 0) return a[i][jR];
 		    }
 		    jR--;
 		    for(int j = jR; j >= jL; j--){
 		        k--;
 		        if(k == 0) return a[iR][j];
 		    }
 		    iR--;
 		    for(int i = iR; i >= iL; i--){
 		        k--;
 		        if(k == 0) return a[i][jL];
 		    }
 		    jL++;
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends