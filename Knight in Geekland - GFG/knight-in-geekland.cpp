//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // int steps = 0;
        // int ans = arr[start_x][start_y];
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int, int>> qu;
        qu.push({start_x, start_y});
        
        qu.push({-1, -1});
        vector<int> ans;
        // int count = 0;
        int temp = arr[start_x][start_y];
        // cout << start_x << " " << start_y << endl;
        // cout << temp << endl;
        arr[start_x][start_y] = -1;
        ans.push_back(temp);
        temp = 0;
        while(!qu.empty()){
            pair<int, int> p = qu.front();
            qu.pop();
            int x = p.first;
            int y = p.second;
            // temp += arr[x][y];
            if(x == -1){
                if(!qu.empty()) qu.push({-1, -1});
                ans.push_back(temp);
                // cout << count << ", " << temp << endl;
                // if(ans < temp){
                //     ans = temp;
                //     steps = count;
                // }
                // count++;
                temp = 0;
            }
            else{
                if(x - 2 >= 0 && y - 1 >= 0 && arr[x - 2][y - 1] != -1){
                    qu.push({x - 2, y - 1});
                    temp += arr[x - 2][y - 1];
                    arr[x - 2][y - 1] = -1;
                }
                if(x - 1 >= 0 && y - 2 >= 0 && arr[x - 1][y - 2] != -1){
                    qu.push({x - 1, y - 2});
                    temp += arr[x - 1][y - 2];
                    arr[x - 1][y - 2] = -1;
                }
                if(x + 2 < n && y - 1 >= 0 && arr[x + 2][y - 1] != -1){
                    qu.push({x + 2, y - 1});
                    temp += arr[x + 2][y - 1];
                    arr[x + 2][y - 1] = -1;
                }
                if(x + 1 < n && y - 2 >= 0 && arr[x + 1][y - 2] != -1){
                    qu.push({x + 1, y - 2});
                    temp += arr[x + 1][y - 2];
                    arr[x + 1][y - 2] = -1;
                }
                if(x - 2 >= 0 && y + 1 < m && arr[x - 2][y + 1] != -1){
                    qu.push({x - 2, y + 1});
                    temp += arr[x - 2][y + 1];
                    arr[x - 2][y + 1] = -1;
                }
                if(x - 1 >= 0 && y + 2 < m && arr[x - 1][y + 2] != -1){
                    qu.push({x - 1, y + 2});
                    temp += arr[x - 1][y + 2];
                    arr[x - 1][y + 2] = -1;
                }
                if(x + 2 < n && y + 1 < m && arr[x + 2][y + 1] != -1){
                    qu.push({x + 2, y + 1});
                    temp += arr[x + 2][y + 1];
                    arr[x + 2][y + 1] = -1;
                }
                if(x + 1 < n && y + 2 < m && arr[x + 1][y + 2] != -1){
                    qu.push({x + 1, y + 2});
                    temp += arr[x + 1][y + 2];
                    arr[x + 1][y + 2] = -1;
                }
            }
        }
        // for(int i = 0; i < ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        int ans1 = ans[ans.size() - 1];
        int count = ans.size() - 1;
        for(int i = ans.size() - 1; i >= 0; i--){
            if(i + ans[i] < ans.size()){
                ans[i] += ans[i + ans[i]];
            }
            if(ans1 <= ans[i]){
                ans1 = ans[i];
                count = i;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends