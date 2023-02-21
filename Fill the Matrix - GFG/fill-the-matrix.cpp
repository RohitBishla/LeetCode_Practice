//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // long long count = (long long)N*(long long)*M;
        x--;
        y--;
        int ans = 0;
        vector<vector<int>> arr(N, vector<int>(M));
        arr[x][y] = 1;
        queue<pair<int, int>> qu;
        qu.push({x, y});
        qu.push({-1, -1});
        while(!qu.empty()){
            pair<int, int> p = qu.front();
            qu.pop();
            x = p.first, y = p.second;
            if(x == -1){
                if(!qu.empty()) qu.push({-1, -1});
                ans++;
            }
            else{
                // arr[x][y] = 1;
                if(x > 0 && arr[x - 1][y] == 0){
                    qu.push({x - 1, y});
                    arr[x - 1][y] = 1;
                }
                if(y > 0 && arr[x][y - 1] == 0){
                    qu.push({x, y - 1});
                    arr[x][y - 1] = 1;
                }
                if(x < N - 1 && arr[x + 1][y] == 0){
                    qu.push({x + 1, y});
                    arr[x + 1][y] = 1;
                }
                if(y < M - 1 && arr[x][y + 1] == 0){
                    qu.push({x, y + 1});
                    arr[x][y + 1] = 1;
                }
            }
        }
        return ans - 1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends